#include<iostream>
using namespace std;

void printArr(int a[],int N){
    for(int i=0;i<N;i++)
        cout<<" "<<a[i];
    cout<<endl;
}

void PermutationOfSetOfNumbers(int a[],int size,int N){
    if(size==1){
        printArr(a,N);
        return;
    }
    for(int i=0;i<size;i++){
        PermutationOfSetOfNumbers(a,size-1,N);
        if(size%2==1)
            swap(a[0],a[size-1]);
        else
            swap(a[i],a[size-1]);
    }
}

int main(){
    	int N;
        cout<<"\nEnter the size of the set of Integers :: ";
        cin>>N;
        int Arr[N];
        for(auto i = 0; i<N;i++){
			cout<<"\n Enter the Element "<<i+1<<" of the set::";
			cin>>Arr[i];
		}
        cout<<"\n SET:: \n {";for(int i=0;i<N;i++){cout<<" "<<Arr[i];};cout<<"}";
        cout<<"\nPermutations of the set :: ";
        cout<<"\n##############################";
        PermutationOfSetOfNumbers(Arr,N,N);
    return 0;
}