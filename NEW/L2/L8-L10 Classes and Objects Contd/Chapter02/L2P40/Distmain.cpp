/*Beginning of Distmain.cpp*/
#include<iostream.h>
#include"Distance.h"
void main()
{
	Distance d1,d2;
	d1.setFeet(5);
	d1.setInches(7.5);
	d2.setFeet(5);
	d2.setInches(6.25);
	Distance& d3=larger(d1,d2);
	d3.setFeet(0);
	d3.setInches(0.0);
	cout<<d1.getFeet()<<" "<<d1.getInches()<<endl;
	cout<<d2.getFeet()<<" "<<d2.getInches()<<endl;
}
/*End of Distmain.cpp*/
