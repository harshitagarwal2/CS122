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
}
float Distance::getInches() //definition
{
	return fInches;
}
Distance Distance::add(Distance dd)
{
	Distance temp;
	temp.iFeet=iFeet+dd.iFeet; 	//legal to access both
								//temp.iFeet and dd.iFeet
	temp.fInches=fInches+dd.fInches; //ditto
	return temp;
}
/*End of Distlib.cpp*/


Conversion of add function by compiler:

Distance add(Distance * const this, Distance dd)
{
	Distance temp;
	temp.iFeet=this->iFeet+dd.iFeet; 	 
	temp.fInches=this->fInches+dd.fInches; 
	return temp;
}
