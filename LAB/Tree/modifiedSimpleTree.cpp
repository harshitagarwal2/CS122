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

    int SearchBT(int,Node*);
    //Copying trees
    Node* Copy(Node*);
    BinTree CopyBT();
    int height(Node*);
     void similarBT(BinTree T)
    {
        //{cout<<"emppty tree";return;}
        int a=similar(root,T.root);
        if(a==0)cout<<"Not similar";
            cout<<"Similar";
    }
    int similar(Node *t1, Node *t2)
    {   if(t1==NULL && t2==NULL)return 1;
        if(t1==NULL || t2==NULL)return 0; //there are two base condition 1) node becomes null
        if(t1->data!=t2->data)return 0; //2) different element found at the respective place
        if(similar(t1->lchild,t2->lchild)==0)return 0;
        if(similar(t1->rchild,t2->rchild)==0)return 0;
    }
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

int BinTree::SearchBT(int item, Node *temp){
    if(temp==NULL)return NULL;   //base condition and return from recursive call
    if(temp->data==item) return 1;   //return from recursive call

        if(SearchBT(item,temp->lchild)==1) return 1;   //return from function

        if(SearchBT(item,temp->rchild)==1) return 1;    //return from function
    }

BinTree BinTree::CopyBT(){
    BinTree t;
    t.root=Copy(root);
    return t;
}

Node* BinTree::Copy(Node* n){

    if(n==NULL)
        return NULL;

    Node* temp;
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

    int a=T.SearchBT(item,T.getroot());

    if(a)
        cout<<"\nElement found";
    else
        cout<<"\nElement not found";

    cout<<"\n\nCopying Tree...";
    T1=T.CopyBT();

     cout<<"\nInOrder of new Tree: ";
    T1.InOrder(T1.getroot());

    cout<<"\n\nHeight of Tree:"<<T.height(T.getroot());
    //similar with two method
    T.similarBT(T1);
//similar with one method
/*int b=T.similar(T.getroot(),T1.getroot());
if(b==0)cout<<" NOT similar";
else if(b==-1)cout<<"NULL";
else cout<<"similar";*/
return 0;
}
