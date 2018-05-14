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
    void Create();
    void Display();
    void InsertLast(int x);
    int IsMember(int);
    LinkedList Union(LinkedList);
    LinkedList Intersection(LinkedList);

};

int LinkedList::IsMember(int item){
    Node *temp;
    if (first == NULL) {cout<<"List is Empty"<<endl;return 0;}

    temp=first;
    while(temp && temp->data!=item) //search the list for given item
            temp=temp->next;
    if (temp==NULL) return 0;
   return 1 ;
}

  void LinkedList::InsertLast(int x){
        Node *temp = new Node(x);

        if (first == NULL) //empty list
        {
            first = temp;
            return ;
        }
        else
        {
            Node *temp1=first;
            while(temp1->next)
                temp1=temp1->next;
            temp1->next=temp;
        }
}
void LinkedList::Create(){
    int item;
    char ans;

    do{
        cout<<"\nEnter the number to be inserted:  ";
        cin>>item;
        InsertLast(item);
        cout<<"\n Do you want to add more elements? [y/n]:    ";
        cin>>ans;
    }

    while(ans=='y' || ans=='Y');


}
LinkedList LinkedList::Union(LinkedList b){

    LinkedList c;

    Node *temp= first;
    while (temp)
    {
        c.InsertLast(temp->data);
        temp=temp->next;
    }

    temp= b.first;
    while(temp){
        if (!IsMember(temp->data))
            c.InsertLast(temp->data);
        temp=temp->next;
    }

    return c;

}

LinkedList LinkedList::Intersection(LinkedList b){
    LinkedList d;

    Node *temp= b.first;
    while (temp)
    {
        if (IsMember(temp->data))
            d.InsertLast(temp->data);
        temp=temp->next;
    }

    return d;

}
void LinkedList::Display()
{
    Node *temp = first;
    cout<<"\nThe linked list contents : "<<endl;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    LinkedList a;
    LinkedList b;
    cout<<"\nCreating first list : "<<endl;
    a.Create();

    a.Display();
    cout<<"\nCreating second list : "<<endl;

    b.Create();

    b.Display();


    LinkedList c = a.Union(b);
    cout<<"\nForming Union of 2 lists "<<endl;
    c.Display();

    LinkedList d = a.Intersection(b);
    cout<<"\nForming Intersection of 2 lists "<<endl;
    d.Display();
    return 0;

}
