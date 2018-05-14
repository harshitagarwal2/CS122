#include<iostream>
using namespace std;

class LinkedQueue;

class Node{
    friend class LinkedQueue;
    int data;
    Node *next;
public:
    Node(int x=0){data = x, next=NULL;}
};

class LinkedQueue{
    Node *Front, *Rear;
public:
    LinkedQueue(){Front=Rear=NULL;}
    void Insert(int x);
    int Delete();
    int IsEmpty(){ return (Front==NULL) && (Rear==NULL);}
    void Contents();
};
void LinkedQueue::Insert(int item){
    Node *temp;
    temp=new Node(item);
    //temp->data = item;
    //temp->next = NULL;
    if (IsEmpty())
        Front= temp;
    else
        Rear->next = temp;
    Rear=temp;

}
int LinkedQueue::Delete(){
    if (IsEmpty()) {cout<<"Queue Underflow"<<endl; return -1;}
    Node *temp = Front;

    Front=Front->next;
    if (Front==NULL) Rear=NULL;
    int item= temp->data;
    delete temp;
    return item;
}
void LinkedQueue::Contents()
{

    if (IsEmpty()){cout<<"Empty Stack"<<endl;return;}
    cout<<"Queue Contains : "<<endl;
    for(Node *temp=Front;temp;temp=temp->next)
        cout<<temp->data<<"  ";
    cout<<endl;
}
int main()
{
    LinkedQueue s;
    s.Insert(10);
    s.Insert(20);
    s.Insert(30);
    s.Insert(40);
    s.Contents();
    cout<<"Item Deleted : "<<s.Delete()<<endl;
    cout<<"Item Deleted : "<<s.Delete()<<endl;

    cout<<"Item Deleted : "<<s.Delete()<<endl;
    cout<<"Item Deleted : "<<s.Delete()<<endl;
        s.Contents();

    s.Insert(50);
    s.Insert(60);
    s.Contents();






}
