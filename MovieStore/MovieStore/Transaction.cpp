#include "Transaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Transaction
// ----------------------------------------------------------------------------
Transaction::Transaction()
{
}

Transaction::Transaction(const string & cmd)
{
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Transaction
// ----------------------------------------------------------------------------
Transaction::~Transaction()
{
}

char Transaction::getIdentifier() const
{
	return identifier;
}
