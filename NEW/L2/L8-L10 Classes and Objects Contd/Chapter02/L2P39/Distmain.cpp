/*Beginning of Distmain.cpp*/
#include<iostream.h>
#include"Distance.h"
void main()
{
	Distance d1,d2,d3;
	d1.setFeet(5);
	d1.setInches(7.5);
	d2.setFeet(3);
	d2.setInches(6.25);
	d3=d1.add(d2);
	cout<<d3.getFeet()<<" "<<d3.getInches()<<endl;
}
/*End of Distmain.cpp*/
