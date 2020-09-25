#include<iostream>
#define debug true

using namespace std;

class Node {
private:
	int data;
	Node* ptr;
public: 
	Node(): ptr(NULL),data(0){  }
	Node(const int & val): ptr(NULL),data(val){  }
	~Node(){
		#if debug==true
			cout<<"\n [DELETION LOG] Node deleted! \t ( "<<data<<" , "<<ptr<<" )";
		#endif
	}
	friend class SinglyLinkedList;
};

/**
 *	This Class Implements the SinglyLinked List
 *
 *  Following API's are exposed :
 *
 *	addNode(int ) : 
 *		@type: void 
 *		@description : Adds a node at the End  
 *  display() : 
 *		@type : void 
 *		@description : Display the Linked List
 *  Search(int ) : 
 *		@type : Node 
 *		@description : Search a given no in the LinkedList and returns the node.
 *  insertAtHead(int) : 
 *		@type : void 
 *		@description : Inserts the Node at Head.
 *  insertAtTail(int ) : 
 *		@type : void 
 *		@description : Inserts the Node at Tail.
 *  insertAtLocation(int,int,int)
 * 		@params : val, loc, verbose
 *		@type : void
 *		@description : Inserts at location or insert at val ( verbose= 1 : insertion after value , verbose=2: insertion at location)
 *  deleteAtHead() : 
 *		@type : void 
 *		@description : Deletes the node at head
 *  deleteAtTail() : 
 *		@type : void 
 *		@description : Deletes the node at Tail (END)
 *  deleteAtLocation(int ): 
 *		@type :void 
 *		@description : Deletes the node at a Location
 *  concat(const SinglyLinkedList *): 
 *		@type :void 
 *		@description : Concatenate two linkedlist
 *
 **/
 
class SinglyLinkedList{
private:
	Node* head;
public:
	SinglyLinkedList() { //constructor
		head = NULL;
	}
	
	
	SinglyLinkedList(const SinglyLinkedList &l){
	 Node* temp = l.head;
	    while (temp!=NULL)
	    {
	        Node* tempcopy = new Node;
	        tempcopy->data = temp->data;
	        temp = temp->ptr;
	    }
	}
	
	//Linked List APIs
	void addNode(int val);
	void display();
	Node* Search(int val);
	void concat(const SinglyLinkedList* _list);
	// API to be added in the Program
	void insertAtHead(const int & val);
	//void insertAtTail(int val);
	void insertAtLocation(int val	// Takes the Data 
						  ,int loc	// takes the postion
						  ,int verbose	// takes 1 for counter
						  );
	void deleteFromHead();
	void deleteFromTail();
	void deleteAtLoc(int val);
	
	//Operator Overloading for concatination	
	SinglyLinkedList & operator+(const SinglyLinkedList  _list){
		Node* temp = this->gethead();
		while(temp->ptr !=NULL){
			temp = temp->ptr;
		}
		temp->ptr = _list.head;
		return *this;
	}
	
	SinglyLinkedList operator+(const SinglyLinkedList &l)
	{
	    SinglyLinkedList l1 = *this;
	    Node *tmp = l1.head;
	
	    while(tmp->ptr!=NULL)
	    {
	        tmp=tmp->ptr;
	    }
	    tmp->ptr = l.head;
	
	    return l1;
	}

	 SinglyLinkedList & operator+=(const SinglyLinkedList & L){
        SinglyLinkedList temp(L);
        if(!head){
            head = temp.head;
        } else {    
            Node* it = head;
            while(it->ptr){
                it = it->ptr;
            }
            it->ptr = temp.head;
        }
        temp.head = 0;
        return *this;
    }
		
	//Getter Attr
	Node* gethead() {
        return head;
    }
    
    //Destructor
	~SinglyLinkedList(){	
		Node* current = head;
		while( current != 0 ) {
    		Node* next = current->ptr;
    		delete current;
	    	current = next;
		}
		head = 0; 
		cout<<"\ndestroyed the Linked List";
	}; //destructor


};

/*
	adds Nodes in the List
	@author : Ausaaf Nabi
	@params : val [int]
	@return : NONE
*/

void SinglyLinkedList::addNode(int val) {
	Node* newNode = new Node();
	newNode->data = val;
	newNode->ptr = NULL;
	if(head == NULL)  {
		head = newNode;
		#if debug==true
			cout << "\n| [CREATION LOG] Created the First Node with value "<<newNode->data<<" |";
		#endif
	} else {
		Node* temp = head;
		while (temp->ptr != NULL) {
			temp = temp->ptr; // goto end of the list
		}
		temp->ptr = newNode;
		#if debug==true
			cout << "\n| [CREATION LOG] Created another Node with value "<<newNode->data<<"  |";
		#endif
	}
}

/*
	Displays the nodes in the Singly Linked List
	@author : Ausaaf
	@returns :  NONE
	
*/
void SinglyLinkedList::display(){
	if(head == NULL) {
		cout << "\nList is empty!" << endl;
	} else {
		Node* temp = head;
		cout << "\nTraversing the Node and printing the data::\n ";
		while(temp != NULL) {
			cout<< temp->data << " -> ";
			temp = temp->ptr;
		}
		cout << endl;
	}
}

/*
	Searches the nodes in the Singly Linked List
	@author : Ausaaf
	@params :  val [int]
	@returns :  Node*
	
*/
Node* SinglyLinkedList::Search(int val){
	Node* curr = head;
	while (curr != NULL){
		if (curr->data== val)
			return curr;
		curr = curr->ptr;
	}
	
	return nullptr;
}

/*
	Insert the node at Head in the Singly Linked List
	@author : Ausaaf
	@params : val [const int &]
	@returns :  NONE
	
*/
void SinglyLinkedList::insertAtHead(const int & val){
  Node *temp = new Node(val);
  temp->ptr = head;
  head = temp;
  #if debug==true
  	cout<<"\n[INSERTION LOG] Node Inserted at head | NEW HEAD LOCATION ::"<<head;
  #endif
  return;
}

/*
	Insert the node at a location in the Singly Linked List
	@author : Ausaaf
	@params : val [int ] , loc [int ],verbose [int ]
	@returns :  NONE
	
*/
void SinglyLinkedList::insertAtLocation(int val, int loc ,int verbose=0){
	a:
	if (verbose == 0){
		// To take loc as the data of the node and search it.
		if (Search(loc) == NULL) {
    		//insertAtStart(val);
    		cout<<"\n Position not Exists";
  		} else if (Search(loc) != NULL) {
  		  	Node *curr = head;
  		  	if(head->data == loc) {
  		  		//prepend the node
  		  	}
			else {
				while(curr->ptr->data != loc) {
					curr = curr->ptr;
				}
				Node* new_node = new Node;
				new_node->data = val;
				new_node->ptr = curr->ptr;
				curr->ptr = new_node;
				#if debug==true
					cout<<"\n[INSERTION LOG] Node Already Exists. INSERTING IT TO loc :: "<<new_node;
				#endif
			}
  		}
	} else if(verbose == 1){
		// To take it as a counter
		cout<<"TO IMPLEMENT! SORRY FOR INCONVINENCE";
		return;
	} else {
		// Redirect to verbose ==0
		verbose =0;
		cout<<"\nUSING VERBOSE=0, Taking loc as data";
		goto a;
	}
} 

/*
	Delete  the head node of  the Singly Linked List
	@author : Ausaaf
	@returns :  NONE
*/
void SinglyLinkedList::deleteFromHead() {
	if(!head) return;
	Node *temp = head;
	head = head->ptr;
	#if debug==true
		cout<<"\n [DELETION LOG] Node Deleted at head | NEW HEAD LOCATION ::"<<head;
	#endif
	delete temp;
	return;
}

/*
	Delete the node at the Tail in the Singly Linked List
	@author : Ausaaf
	@returns :  NONE
	
*/
void SinglyLinkedList::deleteFromTail() {
	if(!head) return;
	Node *temp = head;
	if(temp->ptr ==NULL) {
		#if debug==true
			cout<<"\n [DELETION LOG] Node Deleted at head | LOCATION ::"<<temp;
		#endif
		delete temp;
		return;
	}
	while(temp->ptr->ptr)
		temp = temp->ptr;
	#if debug==true
		cout<<"\n [DELETION LOG] Node Deleted at head | LOCATION ::"<<temp->ptr;
	#endif
	delete temp->ptr;
	temp->ptr=NULL;
	return;
}

/*
	Delete the node At a location  in the Singly Linked List
	@author : Ausaaf
	@params : val [int]
	@returns :  NONE
	
*/
void SinglyLinkedList::deleteAtLoc(int val) {
	if(head==NULL) { cout<<"\nLinked List is Empty!"; return; }
	if(Search(val) != NULL ) {
		Node *temp = head;
		while (temp != NULL) { 
			if(temp->ptr->data == val) {
				cout<<"Deleting...";
				Node *P1 = temp->ptr;
				temp->ptr = P1->ptr;
				delete P1;
				return;
			}
			temp = temp->ptr;
		}
	} else if(Search(val) == NULL) { 
		cout<<"\n Element Not Found!";return;
	}	
}


/*
	Concatenate two Singly Linked List
	@author : Ausaaf
	@params : _list [SinglyLinkedList]
	@returns :  NONE
	
*/
void SinglyLinkedList::concat(const SinglyLinkedList*  _list) {
	Node* temp = this->gethead();
	while(temp->ptr !=NULL){
		temp = temp->ptr;
	}
	temp->ptr = _list->head;
	return;//return *this;
}


/****************************************************
	Driver Code for Testing the API's
	@description : 
	It populates 2 Linked List and Logs the Required information.
	To remove the Logs simply make debug= False at line 2
	@author : Ausaaf
*/
int main() {
	SinglyLinkedList* list = new SinglyLinkedList();
	SinglyLinkedList* list1 = new SinglyLinkedList();
	//SinglyLinkedList* list2 = new SinglyLinkedList();
	cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n==                     TEST LOGGER                  ==";
	cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	//POPULATING WITH TEST DATA
	for(int i=0; i <10; i++)
		list->addNode((i/2)+i*10);
	for(int i=0;i<10;i++)
		list1->addNode(i+i*3);
	cout<<"\n---------------------------------------------";
	cout << "\n\n Linked List Data" << endl;
	list->display();
	cout<<"\n=============================================================";
	list->insertAtLocation(21,84);	
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	list->display();
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	list1->display();
	list->insertAtHead(2);
	list->display();
	list->deleteFromHead();
	list->deleteAtLoc(31);
	list->deleteFromTail();
	list->display();
	list->concat(list1);
	list->display();
	//list += list1;
	//list2 = list + list1;
	//list->display();	
	delete list;
	return 0;
}

