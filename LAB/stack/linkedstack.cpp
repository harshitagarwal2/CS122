#include<iostream>
using namespace std;

class LinkedStack;

class Node{
    friend class LinkedStack;
    int data;
    Node *next;
public:
    Node(int x=0){data = x, next=NULL;}
};

class LinkedStack{
    Node *top;
public:
    LinkedStack(){top=NULL;}
    void Push(int x);
    int Pop();
    int IsEmpty(){ return top==NULL;}
    void Contents();
};
void LinkedStack::Push(int item){
    Node *temp;
    temp=new Node(item);
    //temp->data = item;
    temp->next = top;
    top= temp;
}
int LinkedStack::Pop(){
    if (IsEmpty()) {cout<<"Stack Underflow"<<endl; return -1;}
    Node *temp = top;

    top=top->next;
    int item= temp->data;
    delete temp;
    return item;
}
void LinkedStack::Contents()
{

    if (IsEmpty()){cout<<"Empty Stack"<<endl;return;}
    cout<<"Stack Contains : "<<endl;
    for(Node *temp=top;temp;temp=temp->next)
        cout<<temp->data<<"  ";
    cout<<endl;
}
int main()
{
    LinkedStack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Contents();
    cout<<"Item Popped : "<<s.Pop()<<endl;
    cout<<"Item Popped : "<<s.Pop()<<endl;

    cout<<"Item Popped : "<<s.Pop()<<endl;
    cout<<"Item Popped : "<<s.Pop()<<endl;
    s.Pop();





}
