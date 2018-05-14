/*Beginning of swap01.cpp*/
#include<iostream>
using namespace std;
template <class T>
void Swap(T & a, T & b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int x,y;
	x=10;
	y=20;
	cout<<"Before swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;
	Swap(x,y); //compiler generates swap(int&, int&); and
	//resolves the call
	cout<<"After swapping\n";
	cout<<"x="<<x<<" y="<<y<<endl;
	float X,Y;
	X=10.1;
	Y=20.2;
	cout<<"Before swapping\n";
	cout<<"x="<<X<<" y="<<Y<<endl;
	Swap(X,Y); //compiler generates swap(int&, int&); and
	//resolves the call
	cout<<"After swapping\n";
	cout<<"x="<<X<<" y="<<Y<<endl;

}
/*End of swap01.cpp*/
