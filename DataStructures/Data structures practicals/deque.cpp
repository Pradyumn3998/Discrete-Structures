#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
	Node * prev;
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
class Deque{
    Node*front=nullptr;
    Node*end=nullptr;
    int size=0;
public:
    Deque(){
        cout<<"Deque Created\n";
    }
    ~Deque(){
         while(front!=end){
             Node* temp=front;
             front=front->next;
             delete temp; 
        }
        delete end;
        size=0;
        cout<<"Deque Destroyed\n";
    }
    void enqueueFront(int element);
    void enqueueEnd(int element);
    int dequeueFront();
    int dequeueEnd();
    void display();
    bool isEmpty(){
        return size==0;
    }
};
void Deque::enqueueEnd(int element){
    if(front==nullptr){
        front=new Node(element);
        end=front;
        size++;
        cout<<"Enqueued from Rear :"<<end->data<<endl;
    }
    else{
        end->next=new Node(element,nullptr,end);
        end=end->next;
        size++;
        cout<<"Enqueued from Rear :"<<end->data<<endl;
    }
}
void Deque::enqueueFront(int element){
    if(front==nullptr){
        front=new Node(element);
        end=front;
        size++;
        cout<<"Enqueued from Front :"<<end->data<<endl;
    }
    else{
        front->prev=new Node(element,front,nullptr);
        front=front->prev;
        size++;
        cout<<"Enqueued from Front :"<<front->data<<endl;
    }
}
int Deque::dequeueEnd(){
    if(isEmpty()){
        cout<<"Queue Empty\n";
        return -1;
    }
    else{
        int temp=end->data;
        if(front==end){
            delete front;
            front=(end=nullptr);    
        }
        else{
        Node* trav=end;
        end=end->prev;
        end->next=nullptr;
        delete trav;
        --size;
        }
        return temp;   
    }
}
int Deque::dequeueFront(){
    if(isEmpty()){
        cout<<"Queue Empty\n";
        return -1;
    }
    else{
        int temp=front->data;
        if(front==end){
            delete front;
            front=(end=nullptr);    
        }
        else{
        Node* trav=front;
        front=front->next;
        front->prev=nullptr;
        delete trav;
        --size;
        }
        return temp;   
    }
}
void Deque::display(){
    cout<<"Front::"<<front->data<<endl;
    Node* trav=this->front;
    while(trav!=nullptr){
        cout<<trav->data<<"\t";
        trav=trav->next;
    }
    cout<<endl<<"Rear::"<<end->data<<endl;
}
int main(){
    Deque D;
    D.enqueueEnd(6);
    D.enqueueEnd(5);
    D.enqueueEnd(4);
    D.enqueueEnd(3);
    D.display();
    D.enqueueFront(7);
    D.enqueueFront(8);
    D.display();
    cout<<"Dequeue Front\t"<<D.dequeueFront()<<endl;
    cout<<"Dequeue Front\t"<<D.dequeueFront()<<endl;
    D.display();
    cout<<"Dequeue End\t"<<D.dequeueEnd()<<endl;
    cout<<"Dequeue End\t"<<D.dequeueEnd()<<endl;
    D.display();
    cout<<"Dequeue Rear\t"<<D.dequeueEnd()<<endl;
    cout<<"Dequeue Rear\t"<<D.dequeueEnd()<<endl;
    D.display();
    return 0;
}