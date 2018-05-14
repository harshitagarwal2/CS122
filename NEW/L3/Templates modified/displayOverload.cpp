#include<iostream>
using namespace std;
template <class T>
void display(const T & a)
{
	cout << a << endl;
}

template <class T>
void display(const T & a, const int n) //overloaded version of display()
{
	int ctr;
	for(ctr=0;ctr<n;ctr++)
		cout << a << endl;
}

int main()
{
	char c = 'a';
	int i = 10;
	display(c);
	cout<<endl;
	display(c,3);
	cout<<endl;
	display(i);
	cout<<endl;
	display(i,5);
	cout<<endl;
}
