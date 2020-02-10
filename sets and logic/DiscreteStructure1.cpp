#include <iostream>
#include<math.h>

using namespace std;
void CreateSet(char a[200],int &n);
void isMember(char a[], int n);
void PowerSet(char a[],int n);
int main(){
	char a[200];
	int sizei =0,ch;
	//cout<<"\nEnter the size of the set:: ";
	//cin>>size;
	CreateSet(a,sizei);
	sizei = sizei + 1;
x:
	cout<<"\n#####################################";
	cout<<"\n##             Menu                ##";
	cout<<"\n#####################################";
	cout<<"\n1. Check Membership of the element";
	cout<<"\n2. Print Power Set of the set";
	cout<<"\n3. Exit";
    cout<<"\n Enter your choice :: ";
	cin>>ch;

	if(ch==1)
	isMember(a,sizei);
	else if(ch==2)
	PowerSet(a,sizei);
	else if(ch==3)
        exit(0);
    else
        cout<<"INVALID CHOICE!";

    goto x;
}

void CreateSet(char a[],int &n){
	cout<<"\nEnter the elements for the set";
	for(int i = 0;i<=n;i++){
		char ch;
		cout<<"\nEnter the "<<i+1<<" Element :: ";
		cin>>a[i];
		cout<<"\nWant to enter more (y/n):: ";
		cin>>ch;
		if(ch=='Y' ||ch=='y'){
			++n;
		}
		else if(ch=='N'||ch=='n'){
			break;
		}
		else
			{cout<<"\nInvalid Choice! ";}
	}

	cout<<"\nCardinality :: "<<n+1;
}

void isMember(char a[], int n){
    char mem;
    int flag =0,loc=0;
    cout<<"\nEnter the element you want to search :: ";
    cin>>mem;
    for(int i=0; i<=n;i++){
              loc++;
        if(a[i]==mem){
            flag =1;

            break;
        }
    }
    if(flag==1)
        cout<<"\nElement "<<mem<<" is a member of the set, found at"<<loc++;
    else
        cout<<"\n NOT FOUND!";
}
void PowerSet(char *a,int n){
    int powSize = pow(2, n);
    int counter, j;
    cout<<"\n{";
    for(counter = 0; counter < powSize; counter++)
    {
    for(j = 0; j < n; j++)
    {
        if(counter & (1 << j))
            cout << a[j]<<" ";
    }
    cout << endl;
    }
    cout<<"}";
}



