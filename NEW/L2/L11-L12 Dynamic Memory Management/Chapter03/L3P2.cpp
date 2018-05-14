/*Beginning of DynArray1.cpp*/
#include<iostream.h>
#define SIZE 10
void main()
{
	int * iPtr;
	iPtr = new int[SIZE];
	for(int i=0;i<SIZE;i++)
		iPtr[i]=i; //can write cin>>iPtr[i]; also
	for(int j=0;j<SIZE;j++)
		cout<<iPtr[j]<<endl;
}
/*End of DynArray1.cpp*/
