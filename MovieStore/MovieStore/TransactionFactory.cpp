#include "TransactionFactory.h"

// ----------------------------------------------------------------------------
//	MakeTransaction(string)
//  Create Transaction
// ----------------------------------------------------------------------------
Transaction *& TransactionFactory::MakeTransaction(string command)
{
	// Get command type
	// if type == TransactionType::{TYPE}
	//		split command into chunks according to the type.
	//		create Transaction object, and return it 
}
