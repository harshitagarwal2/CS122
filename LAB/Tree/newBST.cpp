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
    Node* FindMin(Node*);
    Node * getRoot(){return root;};
     void Deletebst(int x);
     Node* Delete(Node*t,int x);
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
            { return 1;}
        else
            if (item<temp->data)
                temp=temp->lchild;
            else
                temp=temp->rchild;
    }
    return 0;
}
/*Node* Bst::Create(int item){
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

void Bst::CreateBst(){

    int item;
    cout<<"Creating the tree : "<<endl;
    cin>>item;
    root=Create(item);
}*/
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


    Node *Bst::FindMin(Node*temp)
            {
                Node*t=temp;
                if(t==NULL)
                    return NULL;

                while(t->lchild!=NULL)
                {
                    t=t->lchild;
                }
                return t;
            }




    void Bst:: Deletebst(int x)
            {
                root=Delete(root,x);
            }



    Node* Bst::Delete(Node*t,int x)
            {

                if(t==NULL)
                    return NULL;

                else if(x<t->data)
                    t->lchild=Delete(t->lchild,x);

                else if(x>t->data)
                t->rchild=Delete(t->rchild,x);

                else  {  //FOUND

                            if(t->rchild==NULL&&t->lchild==NULL)     //LEAF Node
                            {
                                delete t;
                                return NULL;
                            }

                            else                         //ONE CHILD
                                {
                                if(t->lchild==NULL)
                                    {
                                        Node*t2=t->rchild;
                                        delete t;
                                        return t2;
                                    }

                                 else if (t->rchild==NULL)
                                    {
                                        Node*t2=t->lchild;
                                        delete t;
                                        return t2;
                                    }

                                }




                                            //TWO CHILD

                                Node*t2=FindMin(t->rchild);
                                t->data=t2->data;
                               t->rchild= Delete(t->rchild,t->data);


                     }

                            return t;

            }




int main(){
    Bst a;
    int ans,x;
    char an;

do {
    cout<<"enter the element to be inserted";
    cin>>x;
    a.Insert(x);
    cout<<"Do you want to enter more? If no press n";
    cin>>an;
     }while(an!='n');
    cout<<"\nInorder Traversal : ";
    a.Inorder(a.getRoot());
    cout<<"\nPreorder Traversal : ";
    a.Preorder(a.getRoot());
    cout<<"\nPostorder Traversal : ";
    a.Postorder(a.getRoot());
    int item;
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

do{
    cout<<"enter the element to be deleted: ";
         cin>>item;
         a.Deletebst(item);

    a.Inorder(a.getRoot());
    cout<<"Do you want to continue? If not press 0 \t";cout<<endl;
    cin>>ans;
    }while(ans!=0);


    return 0;
}
