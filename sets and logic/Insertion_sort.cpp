#include<iostream>
#include<algorithm>

using namespace std;

void ArrayPopulator(int A[100],int N);
void BubbleSort(int a[],int N);
void PrintArray(int A[],int N);
void swaps(int *a,int *b);

int main(){
	int num;
	cout<<"\nEnter the number of Elements you want to enter:: ";
	cin>>num;
	int A[num];
	cout<<"\n########################################";
	for(auto i = 0; i<num;i++){
		cout<<"\n Enter the Value of Element "<<i+1<<" num::";
		cin>>A[i];
	}
	BubbleSort(A,num);
	//PrintArray(A,num);
	return 0;
}
void swaps(int *a,int *b){
	*a ^=*b^=*a^=*b;
}
void BubbleSort(int a[],int N){
	int iteration=1;
	for(auto i=0;i<N-1;i++){
		int Comparisons =0;
		cout<<"\n#########################################";
		cout<<"\n ITERATION :: "<<iteration<<endl;
		for(auto j=0;j<N-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
			Comparisons++;
		}
		iteration++;
		PrintArray(a,N);
		cout<<"\n COMPARISON ::"<<Comparisons;
	}
}
void ArrayPopulator(int A[],int N){
		cout<<"\n########################################";
		for(auto i = 0; i<N;i++){
			cout<<"\n Enter the Value of Element "<<i+1<<" num::";
			cin>>A[i];
		}
}

void PrintArray(int A[],int N){
   // cout<<"--------------------------------\n";
	for(auto i = 0;i<N;i++){
		cout<<" "<<A[i];
	}
	//cout<<"\n--------------------------------";
}
