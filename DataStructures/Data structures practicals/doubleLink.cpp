#include <iostream>
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
	Node(const Node & a){
		data = a.data;
		next = a.next;
		prev = a.prev;
	}
};
class DoubleLinked{
private:
	int size=0;
	Node *head=nullptr;
	Node *tail=nullptr;

public:

	DoubleLinked(int dat){
		this->head=new Node(dat);
		this->tail=this->head;
	}
	DoubleLinked(){
		this->head=new Node();
		this->tail=this->head;
	}

	~DoubleLinked(){
		Node *trav=this->head;
		///while loop executes untill the value of the head is null
		while (this->head != nullptr) {
  			trav = this->head->next;
 			delete this->head;
  			this->head=trav;
		}
		this->size = 0;
		this->tail=nullptr;
	}

	///insert element at the head
	void addHead(int dat){
		Node *temp=this->head;
		this->head=new Node(dat,temp,nullptr);
		temp->prev=this->head;
		this->size++;
	}

	///insert element in the 'i'th position
	void addAt(int i,int dat){
		if(i+1>this->size){
			cout<<"Cannot add out of bounds\n";
			return;
		}
		if(i==this->size){
			this->addLast(dat);
		}

		Node *trav=this->head;
		for(int pos=0;pos<i-1;pos++){
			trav=trav->next;
		}
		Node *temp=trav->next;
		trav->next=new Node(dat,temp,trav);
		temp->prev=trav->next;
		this->size++;
	}

	///insert element at the last
	void addLast(int dat){
		this->tail->next=new Node(dat,nullptr,this->tail);
		this->size++;
		this->tail=this->tail->next;
	}

	///remove element from the beigininig
	void removeHead(){
		Node *temp= this->head->next;
		delete head;
		this->head = temp;
		this->size--;
	}

	///remove element from the 'i'th position 
	void removeAt(int i){
		if(i>=this->size){
			cout<<"Cannot remove out of bounds\n";
			return;
		}
		Node *trav=this->head;
		for(int pos=0;pos<i-1;pos++){
			trav=trav->next;
		}
		Node *temp=trav->next->next;
		delete trav->next;
		trav->next=temp;
		trav->next->prev=trav;
		this->size--;
	}

	///remove element from the end 
	void removeTail(){
		Node* temp=this->tail->prev;
		delete this->tail;
		this->tail=temp;
		this->size--;
	}

	///returning pointer and checking for the element
	Node* checkElement(int dat){
		Node *trav=this->head;
		while(trav->next!=nullptr){
			if(trav->data==dat){
				cout<<"Element found\n";
				return trav;
			}
			trav=trav->next;
		}
		cout<<"Not found\n";
		return nullptr;
	}

	////adding two list
	 void addTwoList(const DoubleLinked & L2){
	 	this->tail->next=L2.head;
	 	L2.head->prev=this->tail;
	 	this->tail=L2.tail;

	 }

	 ///printing whole list
	 void printList(){
	 	cout<<"\nTraversing from head\n";
	 	this->head->prev=nullptr;
	 	Node *trav=this->head;
	 	while(trav!=nullptr){
	 		cout<<"\t"<<trav->data;
	 		trav=trav->next;
	 	}

	 	cout<<endl<<"Traversing from tail\n";
	 	trav=this->tail;
	 	while(trav!=nullptr){
	 		cout<<"\t"<<trav->data;
	 		trav=trav->prev;
	 	}
	 	cout<<"\n";
	 }

};
int main()
{
	cout<<"\n\tFirst List\n";
	DoubleLinked L1(5);
	L1.addLast(10);
	L1.addLast(11);
	L1.addLast(12);
	L1.addLast(13);
	L1.printList();
	cout<<"\n\tAdding element at 3rd pos \n";
	L1.addAt(2,100);
	L1.printList();
	cout<<"\n\tAdding Head\n";
	L1.addHead(9);
	L1.printList();
	cout<<"\n\tRemoving head\n";
	L1.removeHead();
	L1.printList();
	L1.removeAt(2);
	cout<<"\n\tRemoving the 3rd element\n";
	L1.printList();
	cout<<"\n\tSerching for non existing element\n"<<L1.checkElement(4)<<endl;
	cout<<"\n\tSerching for existing element\n"<<L1.checkElement(5)<<endl;
	cout<<"\n\tSecond List";
	DoubleLinked L2(15);
	L2.addLast(20);
	L2.addLast(21);
	L2.addLast(22);
	L2.addLast(23);
	L2.printList();
	cout<<"\tAdding both list\n";
	L1.addTwoList(L2);
	L1.printList();
	return 0;
}