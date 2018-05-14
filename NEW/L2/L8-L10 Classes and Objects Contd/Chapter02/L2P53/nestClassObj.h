#include <iostream>
using namespace std;
/*Beginning of nestClassObj.h*/
class A
{
    int a;
	class B
	{
	    int b;
		public:
			void BTest();
            //prototype only
            friend class A;
	};
	B B1;
	public:
		void ATest();
};
/*End of nestClassObj.h*/

void A::B::BTest()
{
    b=10;
//definition of A::B::BTest()

}
