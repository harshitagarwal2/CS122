#include <iostream>

using namespace std;

int main()
{
   int x = 100;
   int *ptr = &x;
   cout<<&ptr<<endl;
   cout<<ptr<<endl;
   cout<<*ptr<<endl;
   cout<<x<<endl;
   int y = *ptr;
   *ptr = *ptr + 10;

   int a[100]={15,20,25,30};
   cout<<a<<endl;
   cout<<&a[0]<<endl;
   int *p=a;

   //a[0]=  15; w467=z45
   cout<<*p<<endl;
   p++;
   cout<<*p;

    return 0;
}
