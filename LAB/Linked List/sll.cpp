#include<iostream>
using namespace std;

class LinkedList;//forward decln

class Node{
    friend class LinkedList;
private:
    int data;
    Node *next;
public:
    Node(int x =0){ data = x; next=NULL;}
};

class LinkedList{
    Node *first;
public:
    LinkedList(){first = NULL;}
    void Create2();
    void Display();
    void InsertFront(int x);
    void InsertLast(int x);
    void Delete(int x);
    void Delete2(int x);

    int Search(int);
    Node *Search2(int, Node **);
    void Reverse();

};
void LinkedList::Reverse(){
    Node *p, *q;
    q=NULL;//q follows p

    while(first){
        p=first; //p follows first
        first=first->next;
        p->next = q;
        q=p;

    }
    first = p;

}

void LinkedList::Delete(int item){
    Node *prev, *temp;
    if (first == NULL) {cout<<"List is Empty"<<endl;return;}

    prev= NULL;//pointer to prev node
    temp=first;
    while(temp && temp->data!=item) //search the list for given item
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL){ cout<<"Item Not found"<<endl; return;}
    if (prev==NULL) //deleting first
        first = first ->next;
    else
        prev->next = temp->next;
    delete temp;
}

int LinkedList::Search(int item){
    Node *temp;
    if (first == NULL) {cout<<"List is Empty"<<endl;return 0;}

    temp=first;
    while(temp && temp->data!=item) //search the list for given item
            temp=temp->next;
    if (temp==NULL) return 0;
   return 1 ;
}
void LinkedList::Delete2(int item){
    Node *prev, *temp;
    temp= Search2(30, &prev);

    if (temp)
    {
        cout<<"Previous Node : "<<prev->data<<endl;
        cout<<"Item found" <<temp->data<<endl;
    }
    else
        cout<<"Not found"<<endl;
    prev->next = temp->next;
    delete temp;

}
Node *LinkedList::Search2(int item, Node **prev){
    Node *temp;

    *prev= NULL;//pointer to prev node
    temp=first;
    while(temp && temp->data!=item) //search the list for given item
    {
        *prev=temp;
        temp=temp->next;
    }
    return temp;
}
 void LinkedList::InsertFront(int x){
        Node *temp = new Node(x);
        temp->next = first;
        first = temp;

    }
  void LinkedList::InsertLast(int x){
        Node *temp = new Node(x);

        if (first == NULL) //empty list
        {
            first = temp;
            return;
        }
        Node *temp2 = first;
        while (temp2->next)
            temp2= temp2->next;

        temp2->next = temp;

    }
void LinkedList::Create2(){
    first= new Node(10);
    first->next = new Node(20);

}

void LinkedList::Display()
{
    Node *temp = first;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    LinkedList a;

    //a.Create2();
    cout<<"Insert 10..."<<endl;
    a.InsertFront(10);
    a.Display();

    cout<<"Insert 20 at end..."<<endl;

    a.InsertLast(20);
    a.Display();

    cout<<"Insert 30 at end..."<<endl;

    a.InsertLast(30);
    a.Display();

    cout<<"Insert 40 at end..."<<endl;

    a.InsertLast(40);
    a.Display();

    cout<<"Insert 5 at front..."<<endl;

    a.InsertFront(5);

    a.Display();
    cout<<"Deleting 20..."<<endl;
    a.Delete(20);
    a.Display();
    cout<<"Deleting 5..."<<endl;
    a.Delete(5);
    a.Display();
    cout<<"Deleting 40..."<<endl;
    a.Delete(40);
    a.Display();
    cout<<"Delete 50..."<<endl;
    a.Delete(50);
    a.Display();
    if (a.Search(30))
        cout<<"Item Found"<<endl;
    else
        cout<<"Item Not Found"<<endl;
    a.InsertLast(60);
     a.Delete2(30);
     a.Reverse();
     a.Display();
     cout<<"Insert 70 at end..."<<endl;

    a.InsertLast(70);
    a.Display();
    return 0;

}
