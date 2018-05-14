#include<iostream>
#include<cstdlib>
using namespace std;
class Bintree;//forward decln

//Node structure
class Node{
    friend class Bintree;
private:
    int data;
    Node *rchild;
    Node *lchild;
public:
    Node(int x =0){ data = x; rchild=NULL;lchild=NULL;}
};

class Bintree{
    Node *root;
public:
    Bintree(){root = NULL;}
    Node* Create(int);
        void CreateBinTree();
    void Inorder(Node *);
    void Traversal();


};
Node* Bintree::Create(int item){
    int x;

    if (item!=-1)
    {
        Node *temp = new Node(item);

        cout<<"Enter the lchild of "<<item<<".. Enter -1 if NULL ";
        cin>>x;
        temp->lchild = Create(x);
        cout<<"Enter the rchild of "<<item<<".. Enter -1 if NULL ";
        cin>>x;
        temp->rchild = Create(x);
        return temp;
    }
    return NULL;


}
void Bintree::CreateBinTree(){

    int item;
    cout<<"Creating the tree : "<<endl;
    cout<<"Enter the root (-1 to terminate) : ";
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
void Bintree::Traversal(){
    cout<<"\nInorder Traversal : ";
    Inorder(root);


}

int main(){
    Bintree a;

    a.CreateBinTree();

    cout<<"Given Tree : "<<endl;
    a.Traversal();

    return 0;

}

