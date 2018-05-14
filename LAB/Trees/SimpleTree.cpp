#include<iostream>
#include<cstring>

using namespace std;

class BinTree;

class Node{
    friend class BinTree;
    int data;
    Node *lchild;
    Node *rchild;
public:
    Node(int x=0){
        data=x;
        lchild=rchild=NULL;
    }
};

class BinTree{
    Node *root;
public:
    BinTree(){
        root=NULL;
    }

    Node* getroot();
    void createBT();
    Node* create(int);
    void InOrder(Node*);
    void PreOrder(Node*);
    void PostOrder(Node*);
    void InsertBT(int);
    void SearchBT(int,Node*,int*);
    //Copying trees
    Node* Copy(Node*);
    void CopyBT(BinTree);
    int height(Node*);

};

Node* BinTree::getroot(){
    return root;
}

void BinTree::createBT(){
    int item;
    cout<<"\nCreating BT:\nEnter root:";
    cin>>item;
    root=create(item);
}

Node* BinTree::create(int item){
    int nitem;
    if(item!=-1){
        Node*temp=new Node(item);
        cout<<"Enter the lchild of "<<item<<">";
        cin>>nitem;
        temp->lchild=create(nitem);
        cout<<"Enter the rchild of "<<item<<">";
        cin>>nitem;
        temp->rchild=create(nitem);

        return temp;
    }

    return NULL;
}

void BinTree::InOrder(Node* temp){
    if(temp){
        InOrder(temp->lchild);
        cout<<temp->data<<" ";
        InOrder(temp->rchild);
    }
}

void BinTree::PreOrder(Node* temp){
    if(temp){
        cout<<temp->data<<" ";
        PreOrder(temp->lchild);
        PreOrder(temp->rchild);
    }
}

void BinTree::PostOrder(Node* temp){
    if(temp){
        PostOrder(temp->lchild);
        PostOrder(temp->rchild);
        cout<<temp->data<<" ";
    }
}

void BinTree::InsertBT(int item){

    Node *temp = new Node(item);

    if(root==NULL){
        root=temp;
        return;
    }

     Node *prev,*cur;
     char dir[10];
     int i;
     cout<<"\nEnter the location to be inserted as a string>";
     cin>>dir;

     prev=NULL;
     cur=root;
     for(i=0;i<strlen(dir)&&cur!=NULL;i++){
        prev=cur;
        if(dir[i]=='L')
            cur=cur->lchild;
        else
            cur=cur->rchild;
     }
    if(cur!=NULL||i!=strlen(dir)){
        cout<<"\nCannot Insert!\n";
        return;
    }

    if(dir[i-1]=='L')
        prev->lchild=temp;
    else
        prev->rchild=temp;

}

void BinTree::SearchBT(int item, Node *temp,int *f){

    if(temp&&*f!=1){
        SearchBT(item,temp->lchild,f);
        if(temp->data==item){
            *f=1;
            return;
        }
        SearchBT(item,temp->rchild,f);
    }
}
void BinTree::CopyBT(BinTree t){
    t.root=Copy(root);
}

Node* BinTree::Copy(Node* n){
    Node* temp;
    if(!n)
        return NULL;

    temp=new Node(n->data);

    temp->lchild=Copy(n->lchild);
    temp->rchild=Copy(n->rchild);

return temp;
}

int BinTree::height(Node* temp){
    if(!temp)
        return 0;
    return 1+max(height(temp->lchild),height(temp->rchild));
}

int main(){
    BinTree T,T1;
    int item,flag=0;

    T.createBT();
    cout<<"\nInOrder: ";
    T.InOrder(T.getroot());
    cout<<"\nPreOrder: ";
    T.PreOrder(T.getroot());
    cout<<"\nPostOrder: ";
    T.PostOrder(T.getroot());
    cout<<"\nEnter the item to be inserted>";
    cin>>item;
    T.InsertBT(item);

    cout<<"\nInOrder: ";
    T.InOrder(T.getroot());

    cout<<"\nEnter the item to be searched>";
    cin>>item;

    T.SearchBT(item,T.getroot(),&flag);

    if(flag)
        cout<<"\nElement found";
    else
        cout<<"\nElement not found";

    cout<<"\n\nCopying Tree...";
    T.CopyBT(T1);

     cout<<"\nInOrder of new Tree: ";
    T.InOrder(T.getroot());

    cout<<"\n\nHeight of Tree:"<<T.height(T.getroot());

return 0;
}
