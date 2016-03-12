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
	return false;
}

// ----------------------------------------------------------------------------
//	checkForDuplicates(const Customer &)
//  helper function for insert function
// ----------------------------------------------------------------------------
bool CustomerAccounts::checkForDuplicates(const Customer & account) const
{
	return false;
}