#include "CustomerAccounts.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class CustomerAccounts
// ----------------------------------------------------------------------------
CustomerAccounts::CustomerAccounts()
{
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class CustomerAccounts
// ----------------------------------------------------------------------------
CustomerAccounts::~CustomerAccounts()
{
}

// ----------------------------------------------------------------------------
//	getCustomer(const string &)
//  get customer by hashString
// ----------------------------------------------------------------------------
Customer * CustomerAccounts::getCustomer(const string & hashstring) const
{
	return nullptr;
}

// ----------------------------------------------------------------------------
//	Insert(const string&)
//  Insert customer command
// ----------------------------------------------------------------------------
bool CustomerAccounts::Insert(const string & command)
{
	//command look like ths: 3333 Witch Wicked
	int idTemp;
	Customer tempAccount;
	string firstNameTemp, lastNameTemp;
	stringstream ss;
	ss << command;
	ss >> idTemp;                
	ss >> firstNameTemp;     
	ss >> lastNameTemp;
	tempAccount.setId(idTemp);
	//check if there's already an existing account w/ id
	if (customers.get(to_string(idTemp), tempAccount, tempAccount))
	{
		return false;
	}
	Customer temp(idTemp, firstNameTemp, lastNameTemp);
	customers.Insert(&temp, to_string(idTemp));
	return true;
}