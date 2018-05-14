/*Beginning of newHandler.cpp*/
#define BIG_NUMBER 9999999
#include<new.h> //for set_new_handler() function
void myNewHandler()
{
	/*
	code to handle out-of-memory condition
	*/
}
void main()
{
	new_handler oldHandler;
	//set the function myNewHandler as the new handler
	oldHandler = set_new_handler(myNewHandler);
	int * p = new int[BIG_NUMBER]; //probably cause out-of-
	//memory condition
}
/*End of newHandler.cpp*/
