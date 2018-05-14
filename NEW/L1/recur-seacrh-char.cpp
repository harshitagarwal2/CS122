#include <iostream>
using namespace std;

int Rsearch(char name[], int n, char ch){

if (n == 0)
   return -1; //not found

if (name[n-1]== ch)
    return n-1;

return Rsearch(name, n-1,ch);
}
int main()
{

    char name[100];
    int n;
    char ch;
    cout<<"\nEnter the string: \n";
    cin>>name;
    cout<<"\nEnter the character to be searched : ";
    cin>>ch;
    for(n=0;name[n];n++);
    int pos = Rsearch(name, n, ch);
    if (pos==-1)
        cout<<"\nElement Not found";
    else
        cout<<"\nElement found at "<<pos;
}
