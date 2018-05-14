class A
{
		static int x;
		int y;
	public:
		void abc(int=x); //OK
		void def(int=y); //ERROR!! : object required
};
