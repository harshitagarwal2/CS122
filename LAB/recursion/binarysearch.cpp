#include <iostream>
using namespace std;

int BRsearch(int List[], int l, int h, int x)
{
   int mid;

   if(l>h) return -1;

    mid=( l + h)/2;

    if( x == List[mid])
        return mid;

   else if( x > List[mid])
    {
        l=mid + 1;
        return BRsearch(List, l, h,x);
    }
   else
    {
        h=mid -1;
        return BRsearch(List, l, h,x);
    }



}
int main()
{

    int a[100],n;
    cout<<"Enter no of elements in the list : ";
    cin>>n;
    cout<<"\nEnter the array elements in sorted order: \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cout<<"\nEnter the number to be searched : ";
    cin>>x;
    int low=0;
    int high=n-1;
    int pos = BRsearch(a, low, high, x);
    if (pos==-1)
        cout<<"\nElement Not found";
    else
        cout<<"\nElement found at "<<pos;
}
