#include <iostream>
using namespace std;

void sortR(int lst[], int ln){
int i, tmp, j;
cout<<endl;
for(int j=0;j<ln;j++) cout<<lst[j]<<" ";

if (ln == 1)
   return;
/* find index of smallest no */

for(i = 0; i < ln-1; i++)
  for(j=0;j<ln-1-i;j++)
  {
      if(lst[j]>lst[j+1])
      {
          tmp=lst[j];
          lst[j]=lst[j+1];
          lst[j+1]=tmp;
      }
  }

return sortR(lst, ln-1);
}
int main()
{

    int a[100],n;

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
