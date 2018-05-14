/*Beginning of Distmain.cpp*/
#include<iostream>
using namespace std;
#include"Distance.h"
int main()
{
	Distance d1,d2,d3;
	d1.setFeet(1);
	d1.setInches(1.1);
	d2.setFeet(2);
	d2.setInches(2.2);
	d3=d1.add(d2);
	cout<<d3.getFeet()<<"'-"<<d3.getInches()<<"\"";
}
/*End of Distmain.cpp*/
