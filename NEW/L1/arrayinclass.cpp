#include <iostream>

using namespace std;

const int size=10;

class A
{
    int a[size];
  public:
    int setval( );
    int display( );
    int sortt( );
};
int i ,j, temp;
int A :: setval( )
{
    cout<<"enter 10 values";
    for (i=0; i<size; i++)
        cin >> a[i];
    cout<< endl;
    return 0;
}
int A :: display( )
{
    for(i=0; i<size; i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}

int A::sortt(void)
{
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size ;j++)
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            return 0;
}

int main()
{
    A x;

    x.setval();
    cout<<"original array"<<endl;
    x.display( );
    x.sortt( );
    cout<<"sorted array"<< endl;
    objl.display( );

  return 0;
}

