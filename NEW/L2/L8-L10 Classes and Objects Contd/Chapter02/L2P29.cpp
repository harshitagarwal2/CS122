class B; //forward declaration

class A
{
	int a;
     public:
	void set(){a=10;}
	void get() const {cout<<a<<endl;}
	friend void exchange(A &, B &));
};

class B
{
	int b;
     public:
	void set(){b=20;}
	void get() const {cout<<b<<endl;}
	friend void exchange(A &, B &));
};

void exchange(A & x, B & y)//excahnge the values of private data members of A and B
{

	int t;
	t = x.a;
	x.a  = y.b;
	y.b = t;
}

void main()
{

	A A1;
	B B1;
	
	A1.set();
	B1.set();
	
	cout<<"values before exchange : ";
	A1.get();
	B1.get();
	
	exchange(A1, B1);

	cout<<"values after exchange : ";
	A1.get();
	B1.get();
}