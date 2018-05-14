class A
{
	static A A1; //OK : static
	A * APtr; //OK : pointer
	A A2; //ERROR!! : non - static
};
