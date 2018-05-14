template <class T>
class Stack
{
    int sz;
    T *arr;
   int top;
public:
    Stack(int n)
    {   sz=n;
        arr=new T[n];

        top=-1;
    }
    bool IsEmpty(){ return top==-1;}
    bool IsFull(){return top==sz-1;}
    void Push(T item){
        if (IsFull()) {cout<<"Stack Overflow";return;}
        arr[++top]=item;
    }
    T Pop(){
        if (IsEmpty()){ cout<<"Stack Underflow";return -99;}
        return (arr[top--]);
    }

};

