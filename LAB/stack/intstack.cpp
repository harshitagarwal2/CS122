#include<iostream>
using namespace std;
#define Maxsize 5

class Stack
{
   int arr[Maxsize];
   int top;
public:
    Stack(){top=-1;}
    bool IsEmpty(){ return top==-1;}
    bool IsFull(){return top==Maxsize-1;}
    void Push(int item){
        if (IsFull()) {cout<<"Stack Overflow";return;}
        arr[++top]=item;
    }
    int Pop(){
        if (IsEmpty()){ cout<<"Stack Underflow";return -99;}
        return (arr[top--]);
    }

};

int main(){
    Stack intStk;
    cout<<"Inserting elements ..."<<endl;
    intStk.Push(10);
    intStk.Push(20);
    intStk.Push(30);
    intStk.Push(40);
    intStk.Push(50);
    intStk.Push(10);
    cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;
    cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;
        cout<<"\nElement Popped : " <<    intStk.Pop()<<endl;




}
