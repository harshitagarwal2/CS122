#include<iostream>
using namespace std;

int main()
 {
    int  arr[] = { 31, 54, 77, 52, 93 };
    int* ptr;    		//pointer declaration
    ptr = arr;   		//points to arr
    for(int j=0; j<5; j++)        //for each element,
	cout << "with pointer    "<<*ptr++ <<"   with arr+j   "<<*(arr+j)<<"\n";      	//print value

	/*ptr=arr;
	for(int j=0; j<5; j++)        //for each element,
	cout << "with pointer    "<< * (ptr+j);*/
 }
