#include <iostream>
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

class SingleLinked{
private:
	int size=0;
	Node *head=nullptr;
	Node *tail=nullptr;
public:

	SingleLinked(int dat){
		this->head=new Node(dat,nullptr);
		this->tail=this->head;
	}
	SingleLinked(){
		this->head=new Node();
		this->tail=this->head;
	}

	~SingleLinked(){
		Node *trav=this->head;
		///while loop executes untill the value of the head is null
		while (this->head != nullptr) {
  			trav= this->head->next;
 			delete this->head;
  			this->head=trav;
		}
		this->tail=nullptr;
		size = 0;
	}

	///insert element at the begining
	void addHead(int data){
		this->head=new Node(data,this->head);
		this->size++;
	}

	///insert element at the last
	void addLast(int data){
		Node *trav=this->tail;
		trav->next=new Node(data,nullptr);
		this->size++;
		this->tail=trav->next;
	}

	///insert element at the i index
	void addAt(int i,int data){
		if(i+1>this->size){
			cout<<"Cannot add out of bounds\n";
			return;
		}
		if(i==this->size){
			this->tail->next=new Node(data,nullptr);
			this->tail=this->tail->next;
			this->size++;
			return;
		}

		Node *trav=this->head;
		for(int pos=0;pos<i-1;pos++){
			trav=trav->next;
		}
		trav->next=new Node(data,trav->next);
		this->size++;
	}
	///update element at the given index or position
	void updateAt(int pos, int value){
		if(pos>this->size){
			cout<<"Cannot update out of bounds\n";
			return;
		}
		if(pos==this->size-1){
			this->updateTail(value);
		}
		Node * temp=this->head;
		for (int i = 1; i < pos; ++i){
			temp=temp->next;
		}
		temp->data=value;
		return;
	}

	///update head
	void updateHead(int value){
		this->head->data=value;
	}

	///update tail
	void updateTail(int value){
		this->tail->data=value;
	}

	///remove element from the begining
	void removeHead(){
		Node *temp= this->head->next;
		delete head;
		this->head = temp;
		this->size--;
	}

	///remove element from the i the position
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
		this->size--;
	}

	///returning pointer and checking for element
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
	 void addTwoList(const SingleLinked & L2){
	 	this->tail->next=L2.head;
	 	this->tail=L2.tail;

	 }
	 ///printing whole list
	 void printList(){
	 	Node *trav=this->head;
	 	while(trav!=nullptr){
	 		cout<<"\t"<<trav->data;
	 		trav=trav->next;
	 	}
	 	cout<<endl;
	 }
};


int main()
{
	SingleLinked L1(5);
	L1.addLast(10);
	L1.addLast(11);
	L1.addLast(12);
	L1.addLast(13);
	cout<<"Orignal List\n\n";
	L1.printList();
	cout<<"Adding element in the 3rd pos\n\n";
	L1.addAt(2,100);
	L1.printList();
	cout<<"Adding head in the list\n\n";
	L1.addHead(9);
	L1.printList();
	cout<<"Removing head\n\n";
	L1.removeHead();
	L1.printList();
	cout<<"Removing element from 3rd pos\n\n";
	L1.removeAt(2);
	L1.printList();
	cout<<"\nSerching for non existing element\n"<<L1.checkElement(4)<<endl;
	cout<<"\nSerching for existing element\n"<<L1.checkElement(5)<<endl;
	SingleLinked L2(15);
	L2.addLast(20);
	L2.addLast(21);
	L2.addLast(22);
	L2.addLast(23);
	cout<<"\n\nSecond List\n\n";
	L2.printList();
	cout<<"Adding Both List\n\n\n";
	L1.addTwoList(L2);
	L1.printList();

	return 0;
}
