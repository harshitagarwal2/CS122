/*Beginning of objectSize.cpp*/
#include<iostream>
using namespace std;
struct A
{
	char a;
	int b;
	float c;
};
class B //a class with the same data members
{
	int b;
	float c;
	char a;

};
int main()
{

    cout<<sizeof(A)<<"\n"<<sizeof(B);
}
/*End of objectSize.cpp*/
