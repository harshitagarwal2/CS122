/*Beginning of DistArray.cpp*/
using namespace std;
#include"Distance.h"
#include<iostream>
#define SIZE 3
int main()
{
	Distance dArray[SIZE];
	int a;
	float b;
	for(int i=0;i<SIZE;i++)
	{
		cout<<"Enter the feet : ";
		cin>>a;
		dArray[i].setFeet(a);
		cout<<"Enter the inches : ";
		cin>>b;
		dArray[i].setInches(b);
	}
	for(int i=0;i<SIZE;i++)
	{
		cout<<dArray[i].getFeet()<<" "<<dArray[i].getInches()<<endl;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*End of DistArray.cpp*/
