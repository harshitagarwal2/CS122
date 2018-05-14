void abc(int ** p)
{
	if(memory_not_required)
	{
		delete *p;
		*p = NULL;
	}
	/*
	rest of the abc() function
	*/
}