/*Beginning of DistAddrManip.cpp*/
#include "Distance.h"
#include<iostream.h>
void main()
{
	Distance d1;
	d1.setFeet(256);
	d1.setInches(2.2);
	char * p=(char *)&d1; //explicit address manipulation
	*p=1; //undesirable but unpreventable
	cout<<d1.getFeet()<<" "<<d1.getInches()<<endl;
}
/*End of DistAddrManip.cpp*/
