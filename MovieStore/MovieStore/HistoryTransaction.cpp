#include "HistoryTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class HistoryTransaction
// ----------------------------------------------------------------------------
HistoryTransaction::HistoryTransaction()
{
}

HistoryTransaction::HistoryTransaction(const string & cmd)
{
	char readTransaction;
	int customer_id;            // hold customer id

	stringstream ss;            // string reader
	ss << cmd;
	ss >> readTransaction;
	ss >> customer_id;          // get customer id

	//I think we should validate customer here, basically 
	//if(!isExistingCustomer(customer_id)) 
	//{
	//do nothing or display message for bad line input
	//}
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
