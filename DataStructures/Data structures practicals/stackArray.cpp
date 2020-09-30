#include <iostream>
using namespace std;
template <typename T>
class Stack{
private:
	int size=0;
	int top=-1;
	T *arr;
public:
	Stack(int n){
		size=n;
		arr =new T[n];
		cout<<"Stack Created\n";
	}
	~Stack(){
		delete arr;
		size=0;
		top=-1;
		cout<<"Stack Destroyed\n";
	}
	void push(T element){
		try{
			if(top+1==size)
				throw "Stack overflow";
			arr[++top]=element;
		}
		catch(const char* exp){
			cout<<exp<<endl;
		}
	}
	T pop(){
		try{
			if(top==-1)
				throw "Stack underflow";
			return arr[top--];
		}
		catch(const char* exp){
			cout<<exp<<endl;
			return INT_MIN; ///INT_MIN is like negative infinity for the int and is used to display Stack underflow
		}
	}	
};
int main(){
	int s;
	cout<<"Enter the size of stack\n";
	cin>>s;
	Stack <int> S(s);
	S.push(4);
	S.push(5);
	cout<<S.pop()<<endl;
	cout<<S.pop()<<endl;


	return 0;
} 
