#include<iostream>
#include<math.h>

using namespace std;

class SET{

	protected:
		char a[500];
	public:
        int size;
		SET(){
			size =0;
			a[size] = 0;
		}
		void InputAndDisplay(){

			cout<<"\nEnter the elements for the set";
			for(int i = 0;i<=size;i++){
				char ch;
				cout<<"\nEnter the "<<i+1<<" Element :: ";
				cin>>a[i];
				cout<<"\nWant to enter more (y/n):: ";
				cin>>ch;
				if(ch=='Y' ||ch=='y'){
					++size;
				}
				else if(ch=='N'||ch=='n'){
					break;
				}
				else
				{
					cout<<"\nInvalid Choice! ";
				}
			}
			size +=1;
		}
		void IsSubset(SET obj){
            int i =0,j=0,flag=0;
            for(int i=0;i<this->size;i++){
            	for(int j=0;j<obj.size;j++){
            		if(this->a[i] == obj.a[j]){
            			break;
            		}
            	}
            	if(j==obj.size){
            	flag = 0;
            	}
            }
            flag = 1;
            if(flag ==0){
            	cout<<"\n It is a subset of first";
            }
            else{
            	cout<<"\n It is not a subset of first";
            }
		}
		void Union();
		void Complement();
		SET CartisianProduct(SET obj){
            cout<<"{";
            for(int i =0;i<this->size;i++){
                cout<<endl;
                for(int j=0;j<obj.size;j++){
                    cout<<" { "<<this->a[i]<<" , "<<obj.a[j]<<" } ,";
                }
            } cout<<"\n}";
		}
};

int main(int argc, char const *argv[])
{
	SET s,s1;
	s.InputAndDisplay();
	s1.InputAndDisplay();
	s.IsSubset(s1);
	s.CartisianProduct(s1);
	return 0;
}
