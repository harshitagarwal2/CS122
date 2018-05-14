#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
void bubble_sort(T randNum[], int size);

template <class Item>
void swap1(Item& a, Item& b);

template <class T>
void display_array(T randNum[], int size);

int main()
{

	int *randNum;
	int a,b;
	int size;
	cout << "How many integers?" << endl;
	cin >> size;

	randNum = new int [size];

	 for (int i = 0; i < size; i++)
	 {
		 randNum[i] = 1+ rand() % 10;
	 }

	display_array(randNum, size);

	cout << "\n \n sorted..." << endl;

	bubble_sort( randNum, size); //ERROR

	//display_array(randNum, size);

	system("pause");
	display_array(randNum, size);
	return 0;

}


//=============================
template <class T>
void bubble_sort(T a[], int size)
{
	int i, pass;
	for (pass=0; pass<=size-2; pass++)
	{
		for (i=0; i<=size-2-pass; i++)
		{
			if (a[i] > a[i+1])
				swap(a[i], a[i+1]);

		}
	}

}

template <class Item>
void swap1(Item& a, Item& b)
{
        Item temp;
        temp = a;
        a = b;
        b = temp;
}


template <class T>
void display_array(T randNum[], int size)
{

	 for ( int j = 0; j < size; j++ )
   {

	 cout  << setw(16) << randNum[ j ];

   }

}

