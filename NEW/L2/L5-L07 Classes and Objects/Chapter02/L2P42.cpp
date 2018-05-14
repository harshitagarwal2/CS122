#define SIZE 3
class A
{
		int iArray[SIZE];
	public:
		void setElement(unsigned int,int);
		int getElement(unsigned int);
};
void A::setElement(unsigned int p,int v)
{
	if(p>=SIZE)
		return; //better to throw an exception
	iArray[p]=v;
}
int A::getElement(unsigned int p)
{
	if(p>=SIZE)
		return –1; //better to throw an exception
	return iArray[p];
}
