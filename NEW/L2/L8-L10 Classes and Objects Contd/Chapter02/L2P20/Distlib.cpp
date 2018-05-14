/*Beginning of Distlib.cpp*/
/*Implementation file for the class Distance*/
#include"Distance.h"
void Distance::setFeet(int x)
{
	iFeet=x;
}
int Distance::getFeet() const //constant function
{
	iFeet++; //ERROR!!
	return iFeet;
}
void Distance::setInches(float y)
{
	fInches=y;
}
float Distance::getInches() const //constant function
{
	fInches=0.0; //ERROR!!
	return fInches;
}
Distance Distance::add(Distance dd) const //constant function
{
	Distance temp;
	temp.iFeet=iFeet+dd.iFeet;
	temp.setInches(fInches+dd.fInches);
	iFeet++; //ERROR!!
	return temp;
}
/*End of Distlib.cpp*/
