/*Beginning of Distmain.cpp*/
/*A sample driver program for creating and using objects
of the class Distance*/
#include<iostream.h>
#include“Distance.h”
void main()
{
	Distance d1,d2;
	d1.setFeet(2);
	d1.setInches(2.2);
	d2.setFeet(3);
	d2.setInches(3.3);
	cout<<d1.getFeet()<<“ ”<<d1.getInches()<<endl;
	cout<<d2.getFeet()<<“ ”<<d2.getInches()<<endl;
}
/*End of Distmain.cpp*/
