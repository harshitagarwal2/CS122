/*Beginning of Distmain.cpp*/
#include<iostream.h>
#include“Distance.h”
void main()
{
	Distance d1,d2,d3;
	d1.setFeet(1);
	d1.setInches(1.1);
	d2.setFeet(2);
	d2.setInches(2.2);
	d3=d1.add(d2);
	cout<<d3.getFeet()<<“’-”<<d3.getInches()<<“’’\n”;
}
/*End of Distmain.cpp*/
