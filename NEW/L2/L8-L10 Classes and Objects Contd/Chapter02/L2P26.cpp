#include <iostream.h>

class A;

class B
{
	int p;
   public:
	void setB(){p = 25;}
	void setA(A & a1);//member function of B
};
class A
{
	int q;
    public:
	int getq(){return q;} //member function of A

	friend void B::setA(A & a1);//Member function of B declared as friend
};
void B::setA(A & a1)
{
	a1.q= p; //private members of A are accessed by member function of B
}
void main()
{
	A a;
	B b;
	b.setB();
	b.setA(a);
	cout<<a.getq();


}
