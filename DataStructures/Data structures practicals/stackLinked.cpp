#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
	Node *prev;
	Node(int d,Node* n,Node* p){
		this->next=n;
		this->data=d;
		this->prev=p;
	}
	Node(int d=0){
		this->data=d;
		this->prev=nullptr;
		this->next=nullptr;
	}
};
class Stack{
private:
    Node* top=nullptr;
    Node* head=nullptr;

public:
    Stack();
    ~Stack();
    void push(int element);
    int pop();
    void trav(){
        cout<<"\ttop"<<top->data<<endl;
        Node* tr=head;
        while(tr!=nullptr){
            cout<<tr->data<<endl;
            tr=tr->next;
        }
    }
};

Stack::Stack(){
    cout<<"Stack is created\n";
    head=new Node();
}
Stack::~Stack(){
}
void Stack::push(int element){
    if(top==nullptr){
        head->data=element;
        top=head;
        return;
    }
    try{
        top->next=new Node(element,nullptr,top);
        top=top->next;
        }
    catch(std::bad_alloc& exc){
        cout<<"bad alloc or Stack overflow\n";        
    }  
}
int Stack::pop(){
        if(top==nullptr){
            cout<<"Stack underflow\n";
             return INT_MIN;
        }
        int temp=top->data;
        Node* t=top;
        top=top->prev;
        delete t;
        return temp;

}
int main(){
    Stack S;
    S.push(4);cout<<"pushed : 4"<<endl;
    S.push(5);cout<<"pushed : 5"<<endl;
    S.push(6);cout<<"pushed : 6"<<endl;
    cout<<"Pop :"<<S.pop()<<endl;
    cout<<"Pop :"<<S.pop()<<endl;
    cout<<"Pop :"<<S.pop()<<endl;  
    cout<<"Pop :"<<S.pop()<<endl;  
    return 0;
}
