#include<iostream>
#define UNDIRECTED  0

using namespace std;
struct Node {
    int value;
    Node* next;
};

struct Edge{
    int src,dest;
};

class Graph{
    Node* getAdjNode(int dest,Node* head){
        Node* newNode = new Node;
        newNode->value = dest;
        newNode->next = head;
        return newNode;
    }
    int N;
    
    public:

        Node **head;
        Graph(Edge edges[],int n,int N){
            head = new Node*[N]();
            this->N= N;
            for(int i=0;i<N;i++)
                head[i] = nullptr;
            for(unsigned i=0;i<n;i++){
                int src =edges[i].src;
                int dest = edges[i].dest;
                Node* newNode = getAdjNode(dest,head[src]);
                head[src] = newNode;
              #if Undirected
                newNode = getAdjNode(dest,head[dest]);
                head[dest] = newNode;  
              #endif

            }
        }
        ~Graph(){
            for(int i=0;i<N;i++)
                delete[] head[i];
            delete[] head;
        }
};
void PrintGraph(Node* ptr){
    while(ptr!=nullptr){
        cout<<"-->"<<ptr->value<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    Edge edges[]={
    	{1,5},{1,4},{5,3},{4,1},{4,2},
	{3,1},{3,4},{0,5},{2,0},{1,3}
    };
    int N=6;
    
    int n=sizeof(edges)/sizeof(edges[0]);
    Graph graph(edges,n,N);
    for(int i =0;i<N;i++){
        cout<<i<<" --";
        PrintGraph(graph.head[i]);
    }
    return 0;
}
