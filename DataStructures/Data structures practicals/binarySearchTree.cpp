#include <iostream>
using  namespace std;
class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    int data;
    TreeNode(int d=0,TreeNode* l=nullptr,TreeNode* r=nullptr){
        this->data=d;
        this->left=l;
        this->right=r;
    }
};
class BinarySearchTree{
    TreeNode* root=nullptr;
    int size=0;
    void deleteTree(TreeNode* root);
    public:
    BinarySearchTree(int d);
    ~BinarySearchTree();
    bool isEmpty();
    void addNode(int d);
    void deleteNode(int d);
    void replace(int d);
    void postOrder();
    void inOrder();
    void preOrder();
    void levelTrav();
    int height();
};
///constructor
BinarySearchTree::BinarySearchTree(int d=0){
    root=new TreeNode(d);
        size++;
        cout<<"Binary Search Created\n";
}
///destructor
BinarySearchTree::~BinarySearchTree(){
    deleteTree(this->root);
    cout<<"Binary Search Tree Destroyed\n";
}
///recursive fuction for destructor
void BinarySearchTree::deleteTree(TreeNode* root){
    if(root==nullptr){
        return;
    }
    else{
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
///checking whether Tree is Empty
bool BinarySearchTree:: isEmpty(){
    return size==0;
}
///adding node
void BinarySearchTree:: addNode(int d){
    
}

int main(){
    return 0;
}