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
		t = new ReturnTransaction;
		if (!t->initialize(command))
		{
			delete t;
			t = NULL;
		}
	}
	else if (id == INVENTORY)
	{
		t = new InventoryTransaction;
		if (!t->initialize(command))
		{
			delete t;
			t = NULL;
		}
	}
	else if (id == HISTORY)
	{
		t = new HistoryTransaction;
		if (!t->initialize(command))
		{
			delete t;
			t = NULL;
		}
	}
	else if (id == BORROW)
	{
		t = new BorrowTransaction;
		if (!t->initialize(command))
		{
			delete t;
			t = NULL;
		}
	}
	return t;
}
