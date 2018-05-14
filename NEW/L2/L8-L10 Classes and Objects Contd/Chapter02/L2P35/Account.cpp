/*Beginning of Account.cpp*/
#include"Account.h"
float Account::interest_rate=4.5;

void Account::updateBalance()
{
	if(end_of_year)
		balance+=balance*interest_rate/100;
}
/*
	definitions of the rest of the functions of class Account
*/
/*End of Account.cpp*/
