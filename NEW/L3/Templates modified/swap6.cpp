/*Beginning of swap02.cpp*/
#include<iostream>
using namespace std;
template <class T>
void swap1(T & a, T & b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}


int main()
{
	float x,y;
	x=1.1;
	y=2.2;
	cout<<"Before swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;
	swap1(x,y); //compiler generates swap(float&, float&);
	//and resolves the call
	cout<<"After swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;

	int x1,y1;
	x1=10;
	y1=20;
	cout<<"Before swapping\n";
	cout<<"x1="<<x1<<" y1="<<y1<<endl;
	swap1(x1,y1); //compiler generates swap(float&, float&);
	//and resolves the call
	cout<<"After swapping\n";
	cout<<"x1="<<x1<<" y1="<<y1<<endl;
}
/*End of swap02.cpp*/
