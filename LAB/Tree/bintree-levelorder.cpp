#include<iostream>
#include<cstdlib>
#include<ctype.h>
using namespace std;
#include "stack.h"

class Bintree;//forward decln
class Node{
    friend class Bintree;
    friend class Queue;
private:
    int data;
    Node *rchild;
    Node *lchild;
public:
    Node(int x =0){ data = x; rchild=NULL;lchild=NULL;}
};

class Queue
{
   Node* arr[50];
   int Front;
   int Rear;
public:
    Queue(){Front=Rear=-1;}
    bool IsEmpty(){ return Front==Rear;}
    bool IsFull(){return Rear==49;}
    void Insert(Node* item){
        if (IsFull()) {cout<<"Queue Overflow";return;}
        arr[++Rear]=item;
    }
    Node* Delete(){
        if (IsEmpty()){ cout<<"Queue Underflow";return NULL;}
        return (arr[++Front]);
    }

};

class Bintree{
    Node *root;
public:
    Bintree(){root = NULL;}
    Node* Create(int);
    void CreateBinTree();
    void Inorder(Node *);
    void Preorder(Node *);
    void Postorder(Node *);
    void Traversal();
    void Levelorder();
};

Node* Bintree::Create(int item){
    int x;
    if (item!=-1)
    {

        Node *temp = new Node(item);

        cout<<"Enter the lchild of "<<item<<" ";
        cin>>x;
        temp->lchild = Create(x);
        cout<<"Enter the rchild of "<<item<<" ";
        cin>>x;
        temp->rchild = Create(x);
        return temp;
    }
    return NULL;


}
void Bintree::CreateBinTree(){

    int item;
    cout<<"Creating the tree : "<<endl;
    cin>>item;
    root=Create(item);
}
void Bintree::Inorder(Node *root){
    if (root!=NULL){
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }

}
void Bintree::Preorder(Node *root){
    if (root!=NULL){
        cout<<root->data<<" ";
        Preorder(root->lchild);
        Preorder(root->rchild);
    }

}
void Bintree::Postorder(Node *root){
    if (root!=NULL){
        Postorder(root->lchild);
        Postorder(root->rchild);
        cout<<root->data<<" ";

    }

}
void Bintree::Levelorder(){
    Queue q;
    if (root!=NULL)
        q.Insert(root);
    else
    {cout<<"Empty Tree"; return;}
    while(!q.IsEmpty()){
        Node *temp= q.Delete();
        cout<<temp->data<<" ";
        if (temp->lchild) q.Insert(temp->lchild);
        if (temp->rchild) q.Insert(temp->rchild);

    }

}


void Bintree::Traversal(){
    cout<<"\nInorder Traversal : ";
    Inorder(root);
    cout<<"\npreorder Traversal : ";
    Preorder(root);
    cout<<"\nPostorder Traversal : ";
    Postorder(root);

}

int main(){
    Bintree a;


    a.CreateBinTree();
    a.Traversal();
    cout<<"Level Order Traversal : "<<endl;
    a.Levelorder();


    return 0;

}

