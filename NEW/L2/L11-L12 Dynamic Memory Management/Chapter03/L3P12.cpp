#include<new.h>
void myNewHandler()
{
	//make an attempt to resolve the out-of-memory
	//condition
	if(above_attempt_fails)
		set_new_handler(myAnotherNewHandler);
}