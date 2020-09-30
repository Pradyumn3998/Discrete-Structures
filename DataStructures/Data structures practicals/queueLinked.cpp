#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node *next;
	Node(int d=0,Node* n=nullptr){
		this->next=n;
		this->data=d;
	}
	Node(const Node & a){
		data = a.data;
		next = a.next;
	}
};
class Queue{
    Node* front=nullptr;
    Node* end=nullptr;
public:
    Queue(){
        cout<<"Queue Created\n";
    }
    ~Queue(){
        while(front!=end){
             Node* temp=front;
             front=front->next;
             delete temp; 
        }
        delete end;
        cout<<"Queue Destroyed\n";
    }
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    void display();
};
void Queue::enqueue(int element){
    if(front==nullptr){
        front=new Node(element);
        end=front;
        cout<<"Enqueued :"<<end->data<<endl;
    }
    else{
        end->next=new Node(element,front);
        end=end->next;
        cout<<"Enqueued :"<<end->data<<endl;
    }
}
bool Queue::isEmpty(){
    return front==nullptr;
}
int Queue::dequeue(){
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
        delete trav;
        end->next=front;
        }
        return temp;   
    }
}
void Queue::display(){
    cout<<"Front::"<<front->data<<endl;
    Node *trav=this->front;
	 	do{
	 		cout<<"\t"<<trav->data;
	 		trav=trav->next;
	 	}while(trav!=this->front);
	 	cout<<endl<<"Rear::"<<end->data<<endl;
}
int main(){
    Queue q;
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);

    q.display();
    cout<<"Dequeue\t"<<q.dequeue()<<endl;
    cout<<"Dequeue\t"<<q.dequeue()<<endl;
    cout<<"Dequeue\t"<<q.dequeue()<<endl;
    q.display();
    q.enqueue(1);
    q.display();
    return 0;
}
