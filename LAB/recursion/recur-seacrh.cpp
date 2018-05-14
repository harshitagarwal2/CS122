#include <iostream>
using namespace std;

int Rsearch(int List[], int n, int x){


if (List[n-1]== x)
    return n-1;
else
    if (n>=0)
return Rsearch(List, n-1,x);
return -1;
}
int main()
{

    int a[100],n;
    cout<<"Enter no of elements in the list : ";
    cin>>n;
    cout<<"\nEnter the array elements : \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cout<<"\nEnter the number to be searched : ";
    cin>>x;
    int pos = Rsearch(a, n, x);
    if (pos==-1)
        cout<<"\nElement Not found";
    else
        cout<<"\nElement found at "<<pos;
}
