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
Distance& larger(Distance& dd1, Distance& dd2)
{
	float i,j;
	i=dd1.getFeet()*12+dd1.getInches();
	j=dd2.getFeet()*12+dd2.getInches();
	if(i>j)
		return dd1;
	else
		return dd2;
}
/*End of Distlib.cpp*/
