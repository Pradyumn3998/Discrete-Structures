#include <iostream>
using namespace std;

int fac(int n){
    int f=1;
while(n>0){
    f*=n;
    n--;
}
return f;
}

int per(int x,int y){
    return fac(x)/fac(x-y);
}

int com(int x,int y){
    return fac(x)/(fac(x-y)*fac(y));}

int main()
{
    int x,y;
    cout << "Enter n and r" << endl;
    cin>>x>>y;
    cout<<"Permutation :"<<per(x,y)<<endl;
    cout<<"Combination :"<<com(x,y)<<endl;
    return 0;
}
