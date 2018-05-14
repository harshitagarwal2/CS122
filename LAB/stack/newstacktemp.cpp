 #include<iostream>
using namespace std;
template <class T,int Maxsize>
class Stack
{
   T arr[Maxsize];
   int top;
public:
    Stack(){top=-1;}
    bool IsEmpty(){ return top==-1;}
    bool IsFull(){return top==Maxsize-1;}
    void Push(T item){
        if (IsFull()) {cout<<"Stack Overflow";return;}
        arr[++top]=item;
    }
    T Pop(){
        if (IsEmpty()){ cout<<"Stack Underflow";return NULL;}
        return (arr[top--]);
    }

};

int main(){
    Stack<int, 5> intStk;
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

    Stack<char, 5> chrStk;

    chrStk.Push('A');
    chrStk.Push('B');
    chrStk.Push('C');
    chrStk.Push('D');
    chrStk.Push('E');
    chrStk.Push('F');
    cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;
    cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;

    cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;
        cout<<"\nElement Popped : " <<    chrStk.Pop()<<endl;


}
