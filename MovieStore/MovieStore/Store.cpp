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
	if (action.empty())
	{
		return false;
	}
	string id = action.substr(0, 1);

	//customer accounts
	if (isdigit(id.at(0)))
	{
		if (accounts.Insert(action))
		{
			return true;
		}
		cerr << "Invalid Command: " << action << endl;
		return false;
	}

	//items
	for (int i = 0; i < sizeof(ITEM_IDENTIFIERS) / sizeof(ITEM_IDENTIFIERS[0]); i++)
	{
		if (id == ITEM_IDENTIFIERS[i])
		{
			Item *newItem = NULL;
			newItem = itemFactory.MakeItem(action, id);
			if (newItem != NULL)
			{
				inventory.insert(newItem);
				if (newItem->getIdentifier() == 'C')
				{
					ClassicMovie *temp = dynamic_cast<ClassicMovie*>(newItem);
					string hash = to_string(temp->getReleaseMonth()) + to_string(temp->getReleaseYear()) + temp->getStarringActor();
					classics.Insert(temp, hash);
				}
				return true;
			}
			cerr << "Invalid Command: " << action << endl;
			return false;
		}
	}

	//transactions
	for (int i = 0; i < sizeof(TRANSACTION_IDENTIFIERS) / sizeof(TRANSACTION_IDENTIFIERS[0]); i++)
	{
		if (id == TRANSACTION_IDENTIFIERS[i])
		{
			Transaction *newTransaction = NULL;
			newTransaction = transactionFactory.MakeTransaction(action);
			if (newTransaction != NULL)
			{
				return transactionManager.performTransaction(newTransaction,
					accounts, inventory, classics);
			}
			cerr << "Invalid Command: " << action << endl;
			return false;
		}
	}
	cerr << "Invalid Command: " << action << endl;
	return false;
}
