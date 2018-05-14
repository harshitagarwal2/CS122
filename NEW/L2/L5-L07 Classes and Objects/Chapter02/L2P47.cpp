/*Beginning of longName02.cpp*/
namespace a_very_very_long_name
{
	class A
	{
	};
}
namespace x = a_very_very_long_name; //declaring an alias
void main()
{
	x::A A1; //convenient short name
}
/*End of longName02.cpp*/
