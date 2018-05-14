/*Beginning of Account.cpp*/
#include"Account.h"
float Account::interest_rate = 4.5;
void Account::set_interest_rate(float p)
{
	interest_rate=p; //ok
	cin>>name; //error - cannot access non static member

}
/*
	definitions of the rest of the functions of class Account
*/
/*End of Account.cpp*/

void main()
{

	Account::set_interest_rate(10.5); //calling a static member function w.r.t class
        Account a1;

	a1.set_interest_rate(12.5);//calling a static function using object

}	