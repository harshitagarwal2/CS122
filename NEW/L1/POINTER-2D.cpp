#include<iostream>
using namespace std;

int main(){
    int a[3][3]={ 1,2,3,4,5,6};
    int i,j;
    int (*p)[3];
    cout<<"Given array elements :  "<<endl;
    for( i=0;i<3;i++)
    {
        for( j=0;j<3;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }


    cout<<"Address of individual elements :  "<<endl;
    for( i=0;i<3;i++)
    {
        for( j=0;j<3;j++)
            cout<<&a[i][j]<<"    ";
        cout<<endl;
    }


    p=a;//initialization

    cout<<"\nAddress of first row = &a[0] : "<<&a[0]<<endl; //address of first row
    cout<<"A ddress of first row using pointer = p : "<<p<<endl; //pointer to first row

    cout<<"\nAddress of ith row = &a[1] : "<<&a[1]<<endl;
    cout<<"Address of ith row using pointer = p+1 : "<<p+1<<endl;

    cout<<"\nAddress of first element in ith row = *(p+1) : "<<*(p+1)<<endl;

    cout<<"\nAddress of jth element in ith row = *(p+1)+2  : "<<*(p+1)+2<<endl;
    cout<<"\nValue at a[1][2] = *(*(p+1)+2) : "<<*(*(p+1)+2)<<endl;
}
