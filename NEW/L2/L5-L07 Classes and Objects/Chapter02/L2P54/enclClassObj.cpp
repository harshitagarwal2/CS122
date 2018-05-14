/*Beginning of enclClassObj.cpp*/
#include"enclClassObj.h"
void A::B::BTest(A& ARef)
{
	ARef.ATest(); //OK
}
void A::B::BTest1()
{
	ATest(); //ERROR!!
}
/*End of enclClassObj.cpp*/
