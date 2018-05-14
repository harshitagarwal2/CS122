#include<iostream>
using namespace std;
template<class T>
class Stack
{
	int size ;  // Max number of elements on Stack.
	int top ;
	T* stackPtr ;

public:
	Stack(int = 10) ;
	~Stack() {delete [] stackPtr ; }
	void push(const T&);
	void pop(T&) ;
	int isEmpty()const { return top == -1 ; }
	int isFull() const { return top == size - 1 ; }
	void disp();

} ;
//constructor with the default size 10
template<class T>
Stack<T>::Stack(int s)
{
	size = s > 0 && s < 1000 ? s : 10 ;
	top = -1 ;  // initialize stack
	stackPtr = new T[size] ;
}
 // push an element onto the Stack
template<class T>
void Stack<T>::push(const T& item)
{
	if (!isFull())
           stackPtr[++top] = item ;
	else
	       cout<<"Stack overflow\n"; // push unsuccessful
}
template<class T>   // pop an element off the Stack
void Stack<T>::pop(T&popValue)
{
	if (!isEmpty())

            popValue = stackPtr[top--] ;

	else
	       cout<<"Stack underflow\n"; // pop unsuccessful
}
template<class T>
void Stack<T>::disp()
{
    if (!isEmpty())
	{
        for (int i=0;i<=top;i++)
        cout<<"\t"<<stackPtr[i] ;

	}
	cout<<"Stack empty\n";  //

}
//Instantiation :
int main()
{
    int x;
    Stack  <int> s1(3); //  integer version of class Stack is created
    for (int i=0;i<4;i++)
        s1.push(i);
    s1.pop(x);
    cout<<x<<endl;

    Stack  <float>  f1; // float version of class Stack is created
    f1.push(10.5);
    float f;
    f1.pop(f);
    cout<<f;
    }

