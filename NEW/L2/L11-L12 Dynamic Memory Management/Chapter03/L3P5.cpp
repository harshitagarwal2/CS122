/*Beginning of memleak.cpp*/
#include<iostream.h>
void abc();
void main()
{
	abc(); //call to the abc() function
	/*
	rest of the main() function
	*/
}
void abc()
{
	int * iPtr;
	iPtr = new int;
	/*
	rest of the abc() function
	*/
}
/*End of memleak.cpp*/
