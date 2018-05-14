#include<iostream>
using namespace std;

#include "D:\programs\stack.h"

int main(){
    Stack<char, 5> charstack;
    char str[15];

    cout<<"Enter a string ";
    cin>>str;
    //push chars on to the stack
    for(int i=0; str[i];i++)
        charstack.Push(str[i]);

    int flag=1;
    for(int i=0; str[i];i++)
        if (charstack.Pop()!= str[i])
        {
            flag=0;
            break;
        }
    if (flag==1)
        cout<<"Its a palindrome";
    else
        cout<<"Not a palindrome";
}
