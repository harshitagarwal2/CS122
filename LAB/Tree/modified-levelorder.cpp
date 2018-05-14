#include<iostream>
#include<cstdlib>
#include<ctype.h>
#define Maxsize 50
using namespace std;

class Queue;
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
   Node* arr[Maxsize];
   int Front;
   int Rear;
public:
    Queue(){Front=Rear=-1;}
    int IsEmpty(){ if(Front==-1 && Rear==-1) return 1;
                   return 0;}
    int IsFull(){if( Rear==Maxsize-1)return 1;
                return 0;}
    void Insert(Node* item){
        if (IsFull()) {cout<<"Queue Overflow";}
        else if( IsEmpty()) { Front=0;Rear=0; arr[Rear]=item;}
        else{
            Rear++;
            arr[Rear]=item;
        }


    }
    Node* Delete(){ Node* x;
        if (IsEmpty()){cout<<"Queue Underflow"; return NULL;}
        if(Front==Rear){x=arr[Front]; Front=Rear=-1; return x;}  //only one item was there

         x=arr[Front];
         Front++;
                return x;
    }

};

class Bintree{
    Node *root;
public:
    Bintree(){root = NULL;}
    Node* Create(int);
    void CreateBinTree();
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



int main(){
    Bintree a;
    a.CreateBinTree();
    cout<<"Level Order Traversal : "<<endl;
    a.Levelorder();


    return 0;

}

