#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter size of elements\n";
	cin>>n;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cout<<"Enter element here:\n";
		cin>>arr[i];
	}

bool flag;

//bubble sort to arrange elements in ascending order
for (int i = 0; i < n-1; ++i){
  		bool flag=false;
  		for (int j=0;j<n-1-i;j++){
  			if(arr[j]>arr[j+1]){
  				swap(arr[j],arr[j+1]);
  				flag=true;
  			}
  		}
  		if(!flag){
  			flag=false;
  			break;
  		}
  	}


        //sorted array
        cout<<"Sorted Array\n";
        for (int i = 0; i < n; ++i)
      	{
      		cout<<arr[i]<<"\t";
      	}
        cout<<endl;

  int search,i;
	flag=false;
  cout<<"Enter element to search\n";
    cin>>search;
		cin.ignore();


// linear search program
for(i=0;i<n;i++){
  if (arr[i]==search) {
    flag=true;
    break;
  }
}
if (flag) {
  cout<<"found at position : "<<++i<<endl;
}
else{
  cout<<"Not found\n";
}

	return 0;
}
