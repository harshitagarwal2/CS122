#include<iostream>
using namespace std;

#include "D:\programs\stack.h"


int main(){
    Stack<int, 5> s;
    char exp[20];
    int result;

    cout<<"Enter an postfix expression: ";
    cin>>exp;

    for(int i=0;exp[i];i++)
    {
        if (isdigit(exp[i]))
            s.Push(exp[i]-'0');
        else
        {
            int op2=s.Pop();
            int op1=s.Pop();
            switch(exp[i])
            {

                case '+': result = op1+op2;break;
                case '-':result = op1-op2;break;
                case '*':result = op1*op2;break;
                case '/':result = op1/op2;break;

            }
            s.Push(result);
        }
    }
    cout<<s.Pop();


}
