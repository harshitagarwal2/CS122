#include<iostream>
#include<cstdlib>
#include<ctype.h>
using namespace std;
const int Maxsize =100;
class Bintree;//forward decln
class Stack;

class Node{
    friend class Bintree;
    friend class Queue;
    friend class Stack;
private:
    int data;
    Node *rchild;
    Node *lchild;
public:
    Node(int x =0){ data = x; rchild=NULL;lchild=NULL;}
};

class Stack
{
   Node * arr[Maxsize];
   int top;
public:
    Stack(){top=-1;}
    bool IsEmpty(){ return top==-1;}
    bool IsFull(){return top==Maxsize-1;}
    void Push(Node *item){
        if (IsFull()) {cout<<"Stack Overflow";return;}
        arr[++top]=item;
    }
    Node* Pop(){
        if (IsEmpty()){ cout<<"Stack Underflow";return NULL;}
        return (arr[top--]);
    }

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

Node *ExpressionTree(char postfix[]){
    Node *temp;
    Stack s;

	int i=0, k=0;
	char symbol;
	while((symbol=postfix[i++]))
	{
		Node *temp = new Node(symbol);

		if(isalnum(symbol))		// if operand push it
			s.Push(temp);
		 else				 //else pop element add it to the
		{				    //right of operator node. Pop
			temp->rchild=s.Pop(); // next element and add  to
			temp->lchild=s.Pop();  //left. Push operator node*/
			s.Push(temp);
		}
	}
return(s.Pop());



}
int main(){
    Bintree a;

    char postfix[15];
    cin>>postfix;

    //a.CreateBinTree();
    a.Traversal();
    cout<<"Level Order Traversal : "<<endl;
    a.Levelorder();


    return 0;

}

