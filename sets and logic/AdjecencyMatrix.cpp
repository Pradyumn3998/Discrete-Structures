#include<iostream>
using namespace std;
int AdjMtrx[20][20];
int count =0;

void displayMatrix(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<AdjMtrx[i][j]<<" ";
     cout<<endl;
    }
}    
void add_edge(int a,int b){
    //Function to add edge into the matrix
    AdjMtrx[a][b]=1;
    AdjMtrx[b][a]=1; 
}
bool Validator(int e1,int e2,int nodes){
    if(e1<nodes && e2<nodes) return true;
    else return false;
}

int main(int argc,char* argv[]){
    int nodes;
    cout<<"\n#################################";
    cout<<"\n##        Adjacent Matrix      ##";
    cout<<"\n#################################";
    cout<<"\n## Usage:                      ##";
    cout<<"\n## Enter the nodes:            ##";
    cout<<"\n## Enter the Edge1:            ##";
    cout<<"\n## Enter Edge2                 ##";
    cout<<"\n## continue until you want...  ##";
    cout<<"\n##                             ##";
    cout<<"\n## NOTE: ENTER JUST INTEGERS   ##";
    cout<<"\n#################################";

    cout<<"\nEnter the number of nodes you want to add :";
    cin>>nodes;
    bool n=true;
    do{
        int e1,e2;
        cout<<"\nAdd Edge1 :";cin>>e1;
        cout<<"\nAdd Edge2 :";cin>>e2;
        if(Validator(e1,e2,nodes)==true){
            add_edge(e1,e2);
            cout<<"\nEdge Connected: ("<<e1<<","<<e2<<")";
        }
        else{ n=false; break;}
        cout<<"\nWant to continue....(y/n)";
        char c; cin>>c;
        if(c=='Y' ||c=='y'){n=true;}
        else{n=false;}
    }while(n == true);
    displayMatrix(nodes);
}