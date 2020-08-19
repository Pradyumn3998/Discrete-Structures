#include<iostream>

#pragma hrdstop

using namespace std;

int**  SparseMatrixToCompactMatrix(
    int SparseMatrix[][], //matrix to be converted,
    int row, // length of matrix, 
    int col, // Width of matrix
    int NumberofNonZero
  ){
 
  int **CompactMatrix = new int*[3]; 
  CompactMatrix[3] = new int[NumberofNonZero];
  int k=0;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(SparseMatrix[i][j] != 0){
          CompactMatrix[0][k] = i;
          CompactMatrix[1][k] =j;
          CompactMatrix[2][k]= SparseMatrix[i][j];
          k++;
        }
    }
  }
  return CompactMatrix;
}

void PrintCompactMatrix(int CompactMatrix[][],int col){
  for(int i=0; i<3; i++){
    for(int j=0;j<col;j++){
      cout<<CompactMatrix[i][j]<<"  ";
    }
    cout<<endl;
  }
}
/**
 * Driver Function of the program
 * @params
 *
 **/
int main(){
  cout<<"\n##########################################";
  cout<<"\n#      Sparse Matrix Representation      #";
  cout<<"\n#========================================#";
  cout<<"\n# Please Refer to the Documentation for  #";
  cout<<"\n# Program Usage and other possible info. #";
  cout<<"\n# Test Dataset can be found at code end. #";
  cout<<"\n##########################################";
  cout<<"\n Enter the Rows and Columns for the matrix:\n ";
  
  // Enter the 
  unsigned int row, col;
  cout<<"row:";cin>>row;
  cout<<"col:";cin>>col;

  //Initialized the SparseMatrix
  int SparseMatrix[row][col];
  /*
   * Please use space for seperating the row 
   * and enter to seperate the columns
   * */ 
  int nonZeroDigit = 0;
  cout<<"\n Enter the matrix buffer (seperated by space and return ): \n";
  for(auto i=0;i<row;i++){
    for(auto j=0;j<col;j++){
      cin>>SparseMatrix[i][j];
      if(SparseMatrix[i][j] !=0){
        nonZeroDigit++;
      }
    }
  }
  
  //To add logger and dump matrix
  int ch;
  cout<<"\n 1. Using Threads:";
  cout<<"\n 2. Using Conventional Method:";
  cin>>ch;
  if(ch==1){
    cout<<"to add this function";
  }
  else if(ch==2){
    int** CompactMatrix = SparseMatrixToCompactMatrix(SparseMatrix,row,col,nonZeroDigit);
    cout<<"\n [JOB DONE] Converted a Sparse Matrix To a Compact Matrix";  
  }
  else{
    cerr<<"SORRY! INVALID CHOICE... Program Halted";
  }
  PrintCompactMatrix(CompactMatrix,col);
}
