#include <TMB.hpp>
#include <Eigen/Sparse>
#include <vector>
using namespace density;
using Eigen::SparseMatrix;

// helper function to make sparse SPDE precision matrix
// Inputs:
//    logkappa: log(kappa) parameter value
//    logtau: log(tau) parameter value
//    M0, M1, M2: these sparse matrices are output from R::INLA::inla.spde2.matern()$param.inla$M*
template<class Type>
SparseMatrix<Type> spde_Q(Type logkappa, Type logtau, SparseMatrix<Type> M0,
                          SparseMatrix<Type> M1, SparseMatrix<Type> M2) {
  SparseMatrix<Type> Q;
  Type kappa2 = exp(2. * logkappa);
  Type kappa4 = kappa2*kappa2;
  Q = pow(exp(logtau), 2.)  * (kappa4*M0 + Type(2.0)*kappa2*M1 + M2);
  return Q;
}

template<class Type>
  Type objective_function<Type>::operator() ()
{

  // Data vector of Y (including NAs)
  DATA_VECTOR(Y);



  // Initialize nll
  Type nll = 0.;

  // Using built-in Matern or SPDE?

    DATA_SCALAR(modtype);

    // Get array of realizations to be fit (each year we want to predict)
    PARAMETER_VECTOR(eps);

    if(modtype == 0) {


      // Optimize phi and kappa, given the distance matrix or spde obj
      PARAMETER(phi);
      PARAMETER(kappa);

      // Get distance matrix of full time series
      DATA_MATRIX(D);

      // Matern covariance across year
      matrix<Type> C(D.rows(), D.cols());
      for(int i=0; i<C.rows(); i++) {
        for(int j=0; j<C.cols(); j++) {
          C(i,j) = matern(D(i,j), exp(phi), exp(kappa));
        }
      }

      // Start adding things to the likelihood
      nll += MVNORM(C)(eps);

      SIMULATE{
        REPORT( MVNORM(C)(eps));
      }

      REPORT(C);

    }

    if(modtype == 1) {

      PARAMETER(logtau);           // log of INLA tau param (precision of space-time covariance mat)
      PARAMETER(logkappa);         // log of INLA kappa - related to spatial correlation and range

      // SPDE objects
      DATA_SPARSE_MATRIX(M0);    // used to make gmrf precision
      DATA_SPARSE_MATRIX(M1);    // used to make gmrf precision
      DATA_SPARSE_MATRIX(M2);    // used to make gmrf precision

      SparseMatrix<Type> Q_ss   = spde_Q(logkappa, logtau, M0, M1, M2);
      nll += GMRF(Q_ss,false)(eps);


      REPORT(Q_ss);

      SIMULATE{
        GMRF(Q_ss).simulate(eps);
        REPORT(GMRF(Q_ss,false)(eps));
      }
    }

    if(modtype == 2) {

      PARAMETER(logtau);           // log of INLA tau param (precision of space-time covariance mat)
      PARAMETER(logkappa);         // log of INLA kappa - related to spatial correlation and range

      // SPDE objects
      DATA_SPARSE_MATRIX(M0);    // used to make gmrf precision
      DATA_SPARSE_MATRIX(M1);    // used to make gmrf precision
      DATA_SPARSE_MATRIX(M2);    // used to make gmrf precision


      SparseMatrix<Type> Q_ss = pow(exp(logkappa),2) * M0 + M2; //from Lindgren et al. 2011 when alpha=1
      nll += SCALE( GMRF(Q_ss), 1/exp(logtau))( eps );

      REPORT(Q_ss);

      SIMULATE{
        GMRF(Q_ss).simulate(eps);
        REPORT(GMRF(Q_ss,false)(eps));
      }
    }


    // vector and data of fixed effects
    PARAMETER(a);
    PARAMETER_VECTOR(b);
    DATA_MATRIX(X);

    // Create linear prediction of fixed effects
    vector<Type> lp = X*b + a;

    // Add data IFF Y is not missing

    // Likelihood error
    PARAMETER(logSigma);
    for(int i = 0; i< Y.size(); i++) {
      if(!CppAD::isnan(Y[i])) {
        nll -= dnorm(Y[i], lp[i] + eps[i]  , exp(logSigma), true);
      }
    }

    // ADREPORT(lp);
    // ADREPORT(eps);
    // ADREPORT(a);
    // ADREPORT(b);


    return nll ;
  }
