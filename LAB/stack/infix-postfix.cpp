 #include<iostream>
using namespace std;

#include "D:\harshit bckup\doc\manipal\DS\stack\stack.h"

enum token {Lpar, Rpar, Operand, Operator};

int tokentype(char x)
{
    if (isalpha(x) || isdigit(x))
        return Operand;
    else
        if (x=='(')
            return Lpar;
        else
            if (x==')')
                return Rpar;
            else
                return Operator;
}

int isp(char x){
    switch(x){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        case '#': return -1;
    }

}
int icp(char x){
    switch(x){
        case '(': return 4;
        case '^': return 4;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }

}
void Infix_Postfix  (char infix[], char postfix[])
// Output the postfix form of the infix expression e. Also, ‘#’ is used at the bottom of the stack
{
	Stack<char> s(100); // initialize stack
	char x,y;
	int j=0;
	s.Push('#');
	for (int i=0, x=infix[i]; x!='\0'; i++, x=infix[i])
	{

		switch(tokentype(x))
		{
		case Operand:
		    postfix[j++]=x; break;
		case Rpar:
		    // unstack until ‘(‘
            y = s.Pop();
            while (y!='('){
                postfix[j++]= y;
                y = s.Pop();
            }
            break;
        case Lpar:
            s.Push('(');
            break;
		case Operator:
		    y = s.Pop();
            while(isp(y) >= icp(x)){
                postfix[j++]= y;
                y = s.Pop();
            }
            s.Push(y); // re-stack the last y that was unstacked
            s.Push(x); //push the incoming operator
		}
	}
	 // end of expression; empty stack
	 y = s.Pop();
	 while (y != '#'){
        postfix[j++]= y;
        y = s.Pop();
    }
	postfix[j]='\0';
}

int main()
{
    char infix[100], postfix[100];
    cout<<"Enter an infix expression: ";
    cin>>infix;
    Infix_Postfix(infix,postfix);
    cout<<postfix;

}
