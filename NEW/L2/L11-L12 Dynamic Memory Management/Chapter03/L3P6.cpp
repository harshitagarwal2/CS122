void abc(int ** p)
{
	/*
	some complex algorithm
	*/
	*p = new int;
	/*
	rest of the abc() function
	*/
}
void main()
{
	int * iPtr;
	abc(&iPtr);
	/*
	rest of the main() function
	*/
}