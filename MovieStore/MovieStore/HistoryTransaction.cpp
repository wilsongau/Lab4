#include "HistoryTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class HistoryTransaction
// ----------------------------------------------------------------------------
HistoryTransaction::HistoryTransaction()
{
	customerId = 0;
}


// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class HistoryTransaction
// ----------------------------------------------------------------------------
HistoryTransaction::~HistoryTransaction()
{
}


// ----------------------------------------------------------------------------
//	getCustomerId
//  return customer's id
// ----------------------------------------------------------------------------
int HistoryTransaction::getCustomerId() const
{
	return customerId;
}

// ----------------------------------------------------------------------------
//	operator=
//  assignment operator overload
// ----------------------------------------------------------------------------
HistoryTransaction & HistoryTransaction::operator=(const HistoryTransaction & source)
{
	HistoryTransaction *temp = this;
	if (&source != this)
	{
		*this = source;
	}
	delete temp;
	return *this;
}

bool HistoryTransaction::initialize(const string &cmd)
{
	char readTransaction;
	stringstream ss;            // string reader
	string temp = "";
	ss << cmd;
	ss >> readTransaction;
	ss >> temp;          // get customer id
	if (is_number(temp))
	{
		stringstream(customerId) >> temp;
	}
	return customerId != 0;
}
