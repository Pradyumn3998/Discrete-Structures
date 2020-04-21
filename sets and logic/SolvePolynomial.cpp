#include<iostream>
using namespace std;
//Data Structure of polynomial type
struct Polynomial
{
    int Coefficients,Degree;
};

int ShowExpression(Polynomial Exp[],int Order){
    cout<<"\n Expression :: ";
    cout<<"\n ";
    for(int i=0;i<Order;i++){
        if(Exp[i].Degree>1)
            cout<<Exp[i].Coefficients<<"x^"<<Exp[i].Degree<<" + ";
        else if(Exp[i].Degree==1) 
            cout<<Exp[i].Coefficients<<"x"<<" + ";
        else
            cout<<Exp[i].Coefficients;
    } 
}
int Power(Polynomial Expression, int x){
    int PowerValue=1;
    for(int i=1;i<=Expression.Degree;i++){
        PowerValue *= x; 
    }
    return PowerValue;
}
void SolvePolynomial(Polynomial Expression[],int Order,int x){
    int EvaluatedOutcome=0;
    for(int i=0;i<Order;i++){
        EvaluatedOutcome += Expression[i].Coefficients*Power(Expression[i],x);
    }
    cout<<"\nThe calculated value of f(x) at x="<<x<<" is "<<EvaluatedOutcome;
    cout<<endl;
}
int main(){
    int Order;
   
    cout<<"\n Enter the Order of the Polynomial Function f(x) :: ";
    cin>>Order;
    cout<<endl;
    Polynomial Exp[Order];
    for(int i=0;i<Order;i++){
        cout<<" Enter the Coefficient of "<<i+1<<"th term of the expression:: ";
        cin>>Exp[i].Coefficients;
        cout<<" Enter the Degree of "<<i+1<<"th term of the expression:: ";
        cin>>Exp[i].Degree;
        cout<<endl;
    }
    ShowExpression(Exp,Order);
    cout<<"\n---------------------------------------------";
    int x;
    cout<<"\n Enter the value of x for which f(x) needs to be calculated::";
    cin>>x;
    SolvePolynomial(Exp,Order,x);


    return 0;
}