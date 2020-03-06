#include <iostream>
using namespace std;

class Relation{
public:
    int n;
    int ar[15][15];

    void Setval(){
        cout<<"Enter Relation in Matrix Format : \n";
        for(int i=0;i<n;i++){
                cout<<"Enter in Row "<<i+1<<endl;
            for(int j=0;j<n;j++){
                cout<<"Enter Now :\n";
                cin>>ar[i][j];
            }
        }


    }


bool checkRef(){
    int z=0;
    for(int i=0;i<n;i++){
        if(ar[i][i]==0)
        z=1;
    }
    if(z==1)
        return false;
    else
     return true;


}
int chkSy(){
    int x=0;
    int z=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                    if(ar[i][j]!=ar[j][i]){
                x=1;//x=1 means Anti Symmetric

            }
            }

            if(ar[i][j]!=ar[j][i]){
                z=1;

            }

        }
    }

    if(this->checkRef()&&x==1){
        return 0;//0--->Anti Symmetric
    }
    else if(z==1){
        return 1;//1--->Asymmetric
    }
    else if(z==0){
        return 2;//2--->Symmetric
    }
}
bool chkTrans(){
    int x=0;
    for(int i=0;i<n;i++){
        int c=0;
        int y;
        for(int j=0;j<n;j++){
            if(ar[i][j]){
                for(int k=0;k<n;k++){
                    if(ar[j][k]==1){
                        if(ar[i][k]==1)
                            x=0;
                        else
                            x=1;
                    }
                }
            }
        }
        c=0;
    }
    if(x==0)
        return true;
    else
        return false;
}



Relation(int x){
    n=x;
}

};

int main()
{
    int i;
    cout<<"Enter how many elements are there in the Original Set\n";
    cin>>i;
    Relation x(i);
    x.Setval();
    bool u=x.checkRef();

    int v=x.chkSy();
    bool w=x.chkTrans();
    if(u && w && v==2){
        cout<<"Equivalence Relation\n";
    }
    else if(u && w && v==0){
        cout<<"Partial Order Relation\n";
    }
    else
        cout<<"None\n";


    return 0;
}
