/*Beginning of mutable.h*/
class A
{
		int x;
		mutable int y; //mutable data member
	public:
		void abc() const //a constant member function
		{
			x++; //ERROR: cannot modify a non-constant data
			//member in a constant member function
			y++; //OK: can modify a mutable data member in a
			//constant member function
		}
		void def() //a non-constant member function
		{
			x++; //OK: can modify a non-constant data member
			//in a non-constant member function
			y++; //OK: can modify a mutable data member in a
			//non-constant member function
		}
};
/*End of mutable.h*/
