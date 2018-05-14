#include<iostream>
#include<cstdlib>
using namespace std;

class Bst;//forward decln
class Node{
    friend class Bst;
private:
    int data;
    Node *rchild;
    Node *lchild;
public:
    Node(int x =0){ data = x; rchild=NULL;lchild=NULL;}
};

class Bst{
    Node *root;
public:
    Bst(){root = NULL;}
    Node* Create(int);
    void CreateBst();
    void Inorder(Node *);
    void Preorder(Node *);
    void Postorder(Node *);
    void Insert(int);
    int Search(int item);

    Node * getRoot(){return root;}

    Node * findMax(Node *t)
    {
        if(t==NULL)
            return NULL;
        if(t->rchild == NULL)
            return t;
        return findMax(t->rchild);
    }

         Node * findMin(Node *t)
    {
        if(t==NULL)
            return NULL;
        if(t->lchild == NULL)
            return t;
        return findMin(t->lchild);
    }

    void DeleteBst()
    {   int x;
        cout<<"Enter the ele to delete"<<endl;
        cin>>x;
        root= Delete(root,x);
    }

    Node * Delete(Node *t, int item)
    {
        if(t==NULL)
        {
            cout<<"empty";
            return NULL;
        }

        if(item>t->data)
        {
            t->rchild = Delete(t->rchild,item);
        }
        else if(item<t->data)
        {
            t->lchild = Delete(t->lchild,item);
        }
        else{
                if(t->rchild==NULL && t->lchild==NULL)      //For No Leaf Nodes
                {
                 delete t;
                 return NULL;
                }
                else if(t->rchild==NULL)                    //for One Leaf Node
               {
                    Node *t2 =t->lchild;
                    delete t;
                    return t2;
               }
               else if(t->lchild==NULL)                     //for One Leaf Node at Right
               {
                   Node *t2=t->rchild;
                   delete t;
                   return t2;
               }
               else                                                       //for One Leaf Node
               {
                   Node *t2= findMin(t->rchild);
                   t->data = t2->data;
                   t->rchild=Delete(t->rchild,t2->data);
                   return t;
               }
        }
    }

};

void Bst::Insert(int item){

    Node *temp=new Node(item);

    if (root==NULL) {root = temp; return;}

    Node *prev, *cur;
    prev=NULL;
    cur=root;
    while(cur)            /* traverse until correct position is found*/
    {
        prev=cur;
        if (item==cur->data ){
            cout<<"Duplicates Not allowed\n";
            delete temp;
            return;
        }
        else if (item<cur->data)
                cur=cur->lchild;
             else
                cur=cur->rchild;
    }
    if (item<prev->data)
        prev->lchild = temp;
    else
        prev->rchild = temp;
    return;

}
int Bst::Search(int item){
    Node *temp = root;
    while(temp)
    {
        if (temp->data == item)
             return 1;
        else
            if (item<temp->data)
                temp=temp->lchild;
            else
                temp=temp->rchild;
    }
    return 0;
}
Node* Bst::Create(int item){
    int x;
    if(item!=-1)
    {
        Node *temp = new Node(item);

        cout<<"Enter the lchild of "<<item<<" (smaller) ";;
        cin>>x;
        if(x<item)
        temp->lchild = Create(x);
        cout<<"Enter the rchild of "<<item<<" (greater) ";
        cin>>x;
        if(x>item)
        temp->rchild = Create(x);
        return temp;
    }
    return NULL;


}

void Bst::CreateBst(){

    int item;
    cout<<"Creating the tree : "<<endl;
    cin>>item;
    root=Create(item);
}
void Bst::Inorder(Node *root){
    if (root!=NULL){
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }

}
void Bst::Preorder(Node *root){
    if (root!=NULL){
        cout<<root->data<<" ";
        Preorder(root->lchild);
        Preorder(root->rchild);
    }

}
void Bst::Postorder(Node *root){
    if (root!=NULL){
        Postorder(root->lchild);
        Postorder(root->rchild);
        cout<<root->data<<" ";

    }

}

int main(){
    Bst a;


    a.CreateBst();
    cout<<"\nInorder Traversal : ";
    a.Inorder(a.getRoot());
    cout<<"\nPreorder Traversal : ";
    a.Preorder(a.getRoot());
    cout<<"\nPostorder Traversal : ";
    a.Postorder(a.getRoot());
   /* int item;
    cout<<"\nEnter item to be inserted : ";
    cin>>item;
    a.Insert(item);
    a.Inorder(a.getRoot());
    cout<<"\nEnter item to be searched : ";
    cin>>item;
    if (a.Search(item))
        cout<<"Item Found\n";
    else
        cout<<"Item Not Found\n";
*/
        a.DeleteBst();
cout<<"/nafter deletetion : ";
        a.Inorder(a.getRoot());

}

