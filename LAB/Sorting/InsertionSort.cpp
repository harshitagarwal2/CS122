#include<iostream>
using namespace std;
void Insertionsort(int a[],int n)
{
  int i,j,key;

for(i=1; i<n; i++)
{
      key = a[i];
      j = i-1;
  while(j>=0 &&  a[j]>key)
  {
         a[j+1] = a[j];
          j--;
  }
a[j+1] = key;
}
}

int main()
{
      int a[100],n,i;
      cout<<"Enter number of elements:";
      cin>>n;
      cout<<"Enter the elements\n";
      for(i=0;i<n;i++)
      cin>>a[i];
      cout<<"\nInitial Array:\n";
      for(i=0;i<n;i++)
      {
                      cout<<a[i]<<"\t";
      }
    Insertionsort(a,n);
    cout<<"\nAfter Sorting:\n";
      for(i=0;i<n;i++)
      {
                cout<<a[i]<<"\t";
      }
}



