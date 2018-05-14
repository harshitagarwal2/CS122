/*Beginning of NestedCall.cpp*/
class A
{
		int y;
	public:
		void sety(int);
		void setyindirect(int);
};
void A::sety(int p)
{
	y=p;
}
void A::setyindirect(int q)
{
	sety(q);
}
void main()
{
	A A1;
	A1.setyindirect(1);
}
/*End of NestedCall.cpp*/
