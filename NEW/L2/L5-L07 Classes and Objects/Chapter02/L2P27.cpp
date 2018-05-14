class A;

class B
{
	int p;
   public:
	void setB(){p = 25;}
	void setA(A & a1){ a1.q = p;}//member function of B defined inline 
					ERROR:will not  compile
};
class A
{
	int q;
    public:
	int getq(){return q;} //member function of A

	friend void B::setA(A & a1);//Member function of B declared as friend
};