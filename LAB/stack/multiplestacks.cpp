#include<iostream>

using namespace std;
#include<stdlib.h>

const int Maxsize=5;

class TwoStacks
{
    int arr[Maxsize];
    int top1, top2;
public:
   TwoStacks()  // constructor
   {
       top1 = -1;
       top2 = Maxsize;
   }

   // Method to push an element x to stack1
   void push1(int x)
   {
       // There is at least one empty space for new element
       if (top1+1 < top2)
       {
           top1++;
           arr[top1] = x;
           cout<<"Item pushed into stack 1 : "<<x<<endl;
       }
       else
       {
           cout << "Stack Overflow";
           exit(1);
       }
   }

   // Method to push an element x to stack2
   void push2(int x)
   {
       // There is at least one empty space for new element
       if (top1+1 < top2)
       {
            top2--;
            arr[top2] = x;
            cout<<"Item pushed into stack 2 : "<<x<<endl;

       }
       else
       {
           cout << "Stack Overflow";
           exit(1);
       }
   }

   // Method to pop an element from first stack
   int pop1()
   {
       if (top1 >= 0 )
       {
          int x = arr[top1];
          top1--;
          return x;
       }
       else
       {
           cout << "Stack UnderFlow";
           exit(1);
       }
   }

   // Method to pop an element from second stack
   int pop2()
   {
       if (top2 < Maxsize)
       {
          int x = arr[top2];
          top2++;
          return x;
       }
       else
       {
           cout << "Stack UnderFlow";
           exit(1);
       }
   }
};


/* Driver program to test twStacks class */
int main()
{
    TwoStacks ts;
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);
    ts.push2(11);
    ts.push2(7);
    //ts.push2(25);

    cout << "Popped element from stack1 is " << ts.pop1()<<endl;
    ts.push2(40);
    //cout << "\nPopped element from stack2 is " << ts.pop2()<<endl;
    ts.push1(50);

    return 0;
}
