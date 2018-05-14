#include <iostream>
using namespace std;

void sortR(int list[], int ln){
int i, tmp, min;
cout<<endl;
for(int j=0;j<ln;j++) cout<<list[j]<<" ";

if (ln == 1)
   return;
/* find index of smallest no */
min = 0;
for(i = 1; i < ln; i++)
  if (list[i] < list[min])
     min = i;

/* move smallest element to 0-th element */
tmp = list[0];
list[0] = list[min];
list[min] = tmp;
/* recursive call */

sortR(&list[1], ln-1);
}
int main()
{

    int a[100],n;
    cout<<a;


    cout<<"Enter no of elements in the list : ";
    cin>>n;
    cout<<"\nEnter the array elements : \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"\nSorting Process: \n";
    sortR(a,n);
    cout<<"\nSorted array: \n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
}
