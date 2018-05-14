#include<iostream>
using namespace std;
int * modify(int *b)
{   (*b)++;//*b=*b+1;//is not equvilant to *b++ { it means b++ and then *b} it should be (*b)++;
    return b;
}

int main()

{  int *p,a;
    cin>>a;
    p=&a;
    int *p2= modify(p);
    cout<<*p2;
}
