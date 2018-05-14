#include<iostream>
#include<cstdlib>
#include<ctype.h>
using namespace std;
const int Maxsize =100;
class Bintree;//forward decln
class Stack;

class Node{
    friend class Bintree;

    friend class Stack;
private:
    char data;
    Node *rchild;
    Node *lchild;
public:
    Node(char x ){ data = x; rchild=NULL;lchild=NULL;}
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






class Bintree{
    Node *root;
public:
    Bintree(){root = NULL;}

    void Inorder(Node *);
    void Preorder(Node *);
    void Postorder(Node *);
    Node *ExpressionTree(char postfix[]);
    Node *getRoot(){return root;}
   void expression(char postfix[]){root=ExpressionTree(postfix);}

};


Node * Bintree::ExpressionTree(char postfix[]){
    Node *temp;
    Stack s;

	int i=0;

	while(postfix[i]!='\0')
	{
		Node *temp = new Node(postfix[i]);
        cout<<postfix[i]-'0';
		if(isdigit(postfix[i]))		// if operand push it
			{ // cout<<"\npush  "<<temp->data;
			    s.Push(temp);
			}
		 else				 //else pop element add it to the
		{				    //right of operator node. Pop
			temp->rchild=s.Pop(); // next element and add  to
			temp->lchild=s.Pop();  //left. Push operator node*/
			cout<<"\npop  "<<temp->rchild->data<<"  "<<temp->lchild->data;
			s.Push(temp);
		}
		i++;
	}
	Node *t=s.Pop();

return(t);



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

// This function receives a node of the syntax tree
// and recursively evaluates it
/*int eval(node* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->info);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->info=="+")
        return l_val+r_val;

    if (root->info=="-")
        return l_val-r_val;

    if (root->info=="*")
        return l_val*r_val;

    return l_val/r_val;
}*/

int main(){
    Bintree a;


    char postfix[15];
    cin>>postfix;

    a.expression(postfix);
     cout<<"Pre Order Traversal : "<<endl;
    a.Preorder(a.getRoot());
    cout<<"In Order Traversal : "<<endl;
    a.Inorder(a.getRoot());
     cout<<"Post Order Traversal : "<<endl;
    a.Postorder(a.getRoot());

    return 0;

}

