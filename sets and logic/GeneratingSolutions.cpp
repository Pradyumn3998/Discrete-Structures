#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n , sum ;
    cout<<"Enter number of numbers you want to generate and their Sum:\n";
    cin>>n>>sum;
    cout<<setfill('0')<<setw(n);
    for(int i=0;i<pow(10,n);i++)
    {
        int x=i;
        int s1=0;
        while(x>0){
            int d=x%10;
            s1+=d;
            x/=10;
        }
        if(s1==sum)
            cout<<i<<setfill('0')<<setw(n)<<endl;
        s1=0;
    }


    return 0;
}
