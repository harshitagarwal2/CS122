/*Beginning of DynArray2.cpp*/
#include<iostream.h>
void main()
{
	int * iPtr;
	unsigned int iSize;
	cout<<"Enter the size of the array : ";
	cin>>iSize;
	iPtr = new int[iSize];
	for(int i=0;i<iSize;i++)
	{
		cout<<"Enter the value for element "<<i+1<<" : ";
		cin>>iPtr[i];
	}
	for(int j=0;j<iSize;j++)
		cout<<iPtr[j]<<endl;
}
/*End of DynArray2.cpp*/
