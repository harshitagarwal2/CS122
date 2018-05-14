/*Beginning of friend.cpp*/
class A
{
		int x;
		int y;
	public:
		void setvalue();//member function

		friend float mean(A a); //prototype of the friend function
};

void A::setvalue() {


    x=25;
    y=30;
}

float mean(A a) //definition of the friend function
{
	return float(a.x+a.y)/2.0; //accessing private members of the object
}

void main()
{
	A A1;//object A1
	
	A1.setvalue();

	cout<<"Mean value = "<<mean(A1);
}
/*End of friend.cpp*/
