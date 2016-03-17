#include "TransactionFactory.h"

// ----------------------------------------------------------------------------
//	MakeTransaction(string)
//  Create Transaction
// ----------------------------------------------------------------------------
Transaction * TransactionFactory::MakeTransaction(string command)
{
	Transaction *t = NULL;
	const static string HISTORY = "H";
	const static string INVENTORY = "I";
	const static string BORROW = "B";
	const static string RETURN = "R";
	string id = command.substr(0, 1);
	if (id == RETURN)
	{
		ReturnTransaction *temp = new ReturnTransaction;
		if (temp->initialize(command))
		{
			return dynamic_cast<Transaction*>(temp);
		}
		delete temp;
	}
	else if (id == INVENTORY)
	{
		InventoryTransaction *temp = new InventoryTransaction;
		if (temp->initialize(command))
		{
			return dynamic_cast<Transaction*>(temp);
		}
		delete temp;
	}
	else if (id == HISTORY)
	{
		HistoryTransaction *temp = new HistoryTransaction;
		if (temp->initialize(command))
		{
			return dynamic_cast<Transaction*>(temp);
		}
		delete temp;
	}
	else if (id == BORROW)
	{
		BorrowTransaction *temp = new BorrowTransaction;
		if (temp->initialize(command))
		{
			return dynamic_cast<Transaction*>(temp);
		}
		delete temp;
	}
	return t;
}
