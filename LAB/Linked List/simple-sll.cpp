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

    void Display();
    void InsertFront(int x);
    void InsertLast(int x);

};
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
    cout<<"Insert 60 at end..."<<endl;
    a.InsertLast(60);
     a.Display();
    return 0;

}
