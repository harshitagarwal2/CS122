/*Beginning of DynDist.cpp*/
#include<iostream.h>
#include"Distance.h"
void main()
{
	Distance * dPtr;
	int a,b;
	unsigned int iSize;
	cout<<"Enter the number of elements : ";
	cin>>iSize;
	dPtr = new Distance[iSize];
	for(int i=0;i<iSize;i++)
	{
		cout<<"Enter the feet : ";
		cin>>a;
		cout<<"Enter the inches : ";
		cin>>b;
		dPtr[i].setFeet(a);
		dPtr[i].setInches(b);
	}
	for(int j=0;j<iSize;j++)
	{
		cout<<dPtr[j].getFeet()<<" "<<dPtr[j].getInches()<<endl;
	}
}
/*End of DynDist.cpp*/
