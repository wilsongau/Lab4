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
	string firstNameTemp, lastNameTemp;
	stringstream ss;
	ss << command;
	ss >> idTemp;                
	ss >> firstNameTemp;     
	ss >> lastNameTemp;
	if (!isExistingCustomer(idTemp)) //if there is duplicate
	{
		return false;
	}
	else
	{
		Customer temp(idTemp, firstNameTemp, lastNameTemp);
		customers.Insert(&temp, to_string(idTemp));
		return true;
	}
}

// ----------------------------------------------------------------------------
//	checkForDuplicates(const Customer &)
//  helper function for insert function
// ----------------------------------------------------------------------------
bool CustomerAccounts::isExistingCustomer(const int & id) const //I think isExstingAccount should take const int& id" as paramenter
{
	//go to hashTable of Customers, check ID. If found, then return true
	//---------IMPORTANT: HASH STRING for Customer must be ID only, no last name -- To ensure no double ID.
	return false;
}