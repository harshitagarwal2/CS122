#include<iostream>
using namespace std;

int partition(int a[], int l, int h)
{
  int i, j, pivot, temp;
  pivot = a[l];
  i = l;
  j = h;
  while(1)
  {

   while(a[i] < pivot )
   i++;
   while(a[j] > pivot )
   j--;
   if(i < j)
   {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
   }
   else
   {
    return j;
   }
  }
}

void quicksort(int a[], int l, int h)
{
  if(l < h)
  {
    int p;
    p = partition(a, l, h);
    quicksort(a, l, p-1);
    quicksort(a, p+1, h);
  }
}


int main()
{
      int a[100],n,l,h,i;
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
      h=n-1;
      l=0;
      quicksort(a,l,h);
      cout<<"\nAfter Sorting:\n";
      for(i=0;i<n;i++)
      {
                cout<<a[i]<<"\t";
      }


}
