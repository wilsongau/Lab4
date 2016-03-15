#include "HistoryTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class HistoryTransaction
// ----------------------------------------------------------------------------
HistoryTransaction::HistoryTransaction()
{
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
