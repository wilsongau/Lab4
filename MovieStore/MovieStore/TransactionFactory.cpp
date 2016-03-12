#include "TransactionFactory.h"

// ----------------------------------------------------------------------------
//	MakeTransaction(string)
//  Create Transaction
// ----------------------------------------------------------------------------
Transaction *& TransactionFactory::MakeTransaction(string command)
{
	Transaction *t = NULL;
	const static string HISTORY = "H";
	const static string INVENTORY = "I";
	const static string BORROW = "B";
	const static string RETURN = "R";
	string id = command.substr(0, 1);
	if (id == RETURN)
	{
		t = new ReturnTransaction(command);
	}
	else if (id == INVENTORY)
	{
		t = new InventoryTransaction(command);
	}
	else if (id == HISTORY)
	{
		t = new HistoryTransaction(command);
	}
	else if (id == BORROW)
	{
		t = new BorrowTransaction(command);
	}
	else 
	{
		cerr << "ERROR, invalid command: " << command;
	}
	return t;
}
