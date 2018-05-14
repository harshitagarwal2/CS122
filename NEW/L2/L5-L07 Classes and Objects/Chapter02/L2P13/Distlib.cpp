/*Beginning of Distlib.cpp*/
/*Implementation file for the class Distance*/
#include"Distance.h"
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
/*End of Distlib.cpp*/
