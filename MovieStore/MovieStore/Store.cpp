#include "Store.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Store
// ----------------------------------------------------------------------------
Store::Store()
{
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Store
// ----------------------------------------------------------------------------
Store::~Store()
{
}

// ----------------------------------------------------------------------------
//	ReadAction(const string &)
// Based on action will creates the customer list depending on the parameter's 
// contents, route transactions to TransactionFactory, and items to ItemFactory 
// ----------------------------------------------------------------------------
bool Store::ReadAction(const string & action)
{
	string id = action.substr(0, 1);
	if (isdigit(id.at(0)))
	{
		if (accounts.Insert(action))
		{
			return true;
		}
	}
	for (int i = 0; i < sizeof(ITEM_IDENTIFIERS) / sizeof(ITEM_IDENTIFIERS[0]); i++)
	{
		if (id == ITEM_IDENTIFIERS[i])
		{
			Item *newItem = NULL;
			newItem = itemFactory.MakeItem(action);
			if (newItem != NULL)
			{
				inventory.insert(newItem);
				return true;
			}
		}
	}
	for (int i = 0; i < sizeof(TRANSACTION_IDENTIFIERS) / sizeof(TRANSACTION_IDENTIFIERS[0]); i++)
	{
		if (id == TRANSACTION_IDENTIFIERS[i])
		{
			Transaction *newTransaction = NULL;
			newTransaction = transactionFactory.MakeTransaction(action);
			if (newTransaction != NULL)
			{
				transactionManager.performTransaction(newTransaction, accounts, inventory);
				return true;
			}
		}
	}
	cerr << "Invalid Command: " << action << endl;
}
