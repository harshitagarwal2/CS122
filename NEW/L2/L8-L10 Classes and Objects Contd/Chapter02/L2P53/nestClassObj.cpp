/*Beginning of nestClassObj.cpp*/
#include"nestClassObj.h"
void A::ATest()
{
	B1.BTest();
	a=B1.b;
	B B2;
	B2.BTest();
	cout<<a;
}

int main()
{
    A a1;
    a1.ATest();
}
/*End of nestClassObj.cpp*/
