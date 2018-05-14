#include<iostream>
using namespace std;

class DLinkedList;//forward decln
class Node{
    friend class DLinkedList;
private:
    int data;
    Node *rlink;
    Node *llink;
public:
    Node(int x =0){ data = x; rlink=NULL;llink=NULL;}
};

class DLinkedList{
    Node *first, *last;
public:
    DLinkedList(){first = NULL;last =NULL;}
    int IsEmpty(){ return (first==NULL)&& (last==NULL)? 1: 0;}
    void Create();
    void Display();
    void InsertFirst(int x);
    void InsertLast(int x);
    void Delete(int x);
    int Search(int);
    void Reverse();

};

void DLinkedList::Reverse(){
    /*Node *p, *q,*r;
    q=NULL;//q follows p
    r=first;
    last=r;
    while(r){
        p=r; //p follows first
        r=r->rlink;
        p->rlink = q;
        p->llink=r;
        q=p;

    }
    first = p;*/
    Node *p, *q;
    q=NULL;
    last=first;
    while(first)
    {
        p=first;
        first=first->rlink;
        p->rlink=q;
        p->llink=first;
        q=p;
    }
first=p;
}



int DLinkedList::Search(int item){
    Node *temp;
    if (IsEmpty()) {cout<<"List is Empty"<<endl;return 0;}

    temp=first;
    while(temp && temp->data!=item) //search the list for given item
            temp=temp->rlink;
    if (temp==NULL) return 0;
   return 1 ;
}

void DLinkedList::InsertLast(int x)
{
        Node *temp = new Node(x);

        if (IsEmpty()) //empty list
        {
            first = temp;
            last = temp;
            return ;
        }
        else
        {
            last->rlink = temp;
            temp->llink = last;
            last = temp;
        }
}

void DLinkedList::Delete(int item){
    Node *prev, *next,*temp;

    if (IsEmpty()) {cout<<"List is Empty"<<endl;return;}

    temp=first;
    while(temp && temp->data!=item) //search the list for given item
        temp=temp->rlink;

    if (temp==NULL){ cout<<"Item Not found"<<endl; return;}
    prev=temp->llink;
    next=temp->rlink;
    if (prev) //deleting first
        prev->rlink = next;
    else //deleting first node
        first = next;
    if (next)
        next->llink = prev;
    else//deleting last node
        last=prev;

    delete temp;
}
 void DLinkedList::InsertFirst(int x){
        Node *temp = new Node(x);



        if (IsEmpty()) {//empty list
            first = temp;
            last=temp;
        }
        else
        {
            first->llink=temp;
            temp->rlink = first;

            first=temp;
        }


}

void DLinkedList::Create(){
    int item;
    cout<<"Enter the number to be inserted: [-99 to end] ";
    cin>>item;
    while(item!=-99)
    {
        InsertLast(item);
        cout<<"Enter the number to be inserted: [-99 to end] ";
        cin>>item;

    }

}

void DLinkedList::Display()
{
    Node *temp = first;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->rlink;
    }
    cout<<endl;
}
int main(){
    DLinkedList a;


    cout<<"Creating the list : "<<endl;
    a.Create();

    a.Display();
    a.InsertFirst(5);
    a.Display();
    a.Delete(5);
    a.Display();
    a.Delete(50);
    a.Display();
    a.Reverse();
    a.Display();

    return 0;

}

