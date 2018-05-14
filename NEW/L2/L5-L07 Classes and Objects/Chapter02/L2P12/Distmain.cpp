/*Beginning of DistAddrManip.cpp*/
#include<iostream>
using namespace std;

class Distance
{
		int iFeet;
		float fInches;
	public:
		void setFeet(int); //prototype only
		int getFeet(); //prototype only
		void setInches(float); //prototype only
		float getInches(); //prototype only
		Distance add(Distance);
};
/*End of Distance.h*/
void Distance::setFeet(int x) //definition
{
	iFeet=x;
}
int Distance::getFeet() //definition
{
	return iFeet;
}
void Distance::setInches(float y) //definition
{
	fInches=y;
	if(fInches>=12)
	{
		iFeet+=fInches/12;
		fInches-=((int)fInches/12)*12;
	}
}
float Distance::getInches() //definition
{
	return fInches;
}
Distance Distance::add(Distance dd)
{
	Distance temp;
	temp.iFeet=iFeet+dd.iFeet;
	temp.setInches(fInches+dd.fInches);
	return temp;
}

int main()
{
	Distance d1;
	d1.setFeet(256);
	d1.setInches(2.2);
	char * p=(char *)&d1; //explicit address manipulation
	*p=1; //undesirable but unpreventable
	cout<<d1.getFeet()<<" "<<d1.getInches()<<endl;
	return 0;
}
/*End of DistAddrManip.cpp*/
