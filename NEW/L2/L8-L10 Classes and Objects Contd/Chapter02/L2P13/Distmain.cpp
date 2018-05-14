/*Beginning of PointerToMember.cpp*/
#include<iostream.h>
#include "Distance.h"
void main()
{
	Distance d1; //object
	Distance * dPtr; //pointer
	dPtr=&d1; //pointer initialized
	dPtr->setFeet(1); //calling member functions
	dPtr->setInches(1.1); //through pointers
	/*Same as d1.setFeet(1) and d1.setInches(1.1)*/
	cout<<dPtr->getFeet()<<" "<<dPtr->getInches()<<endl;
	/*Same as d1.getFeet() and d1.getInches()*/
}
/*End of PointerToMember.cpp*/
