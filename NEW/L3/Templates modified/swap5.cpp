
#include<iostream>
using namespace std;
template <class T>
void swap1(T & a, T & b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

class Distance
{
	int iFeet;
	float fInches;

	public:
	Distance(); //prototypes provided by the
				//library programmer
	Distance(int,float); //prototype of the parameterized
						//constructor

	void setFeet(int); //prototype only
	int getFeet(); //prototype only
	void setInches(float); //prototype only
	float getInches(); //prototype only
};
Distance::Distance()
{
	iFeet=0;
	fInches=0.0;
}
Distance::Distance(int p, float q)
{
	iFeet=p;
	setInches(q);
}
/*
	definitions of the rest of the functions of class 	Distance */

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


int main()
{
	int x,y;
	x=10;
	y=20;
	cout<<"Before swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;
	swap1(x,y); //compiler generates swap(int&, int&); and resolves the call
	cout<<"After swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;
	//----------------------------------------
	float f1,f2;
	f1=1.1;
	f2=2.2;
	cout<<"Before swapping\n";
	cout<<"f1="<<f1<<" f2="<<f2<<endl;
	swap1(f1,f2); //compiler generates swap(float&, float&);
	//and resolves the call
	cout<<"After swapping\n";
	cout<<"f1="<<f1<<" f2="<<f2<<endl;

	//-------------------------
	Distance d1(1,1.1),d2(2,2.2);
	cout<<"Before swapping\n";
	cout<<"d1="<<d1.getFeet()<<"'    "<<d1.getInches()<<"''\n";
	cout<<"d2="<<d2.getFeet()<<"'    "<<d2.getInches()<<"''\n";
	swap1(d1,d2); //compiler generates swap(Distance&,
				//Distance&); and resolves the call
	cout<<"After swapping\n";
	cout<<"d1="<<d1.getFeet()<<"'   "<<d1.getInches()<<"''\n";
	cout<<"d2="<<d2.getFeet()<<"'   "<<d2.getInches()<<"''\n";

	return 0;
}





