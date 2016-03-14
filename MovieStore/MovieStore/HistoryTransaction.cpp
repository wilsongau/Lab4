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

HistoryTransaction & HistoryTransaction::operator=(const HistoryTransaction & t)
{
	// TODO: insert return statement here
}
