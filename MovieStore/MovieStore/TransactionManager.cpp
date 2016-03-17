#include "TransactionManager.h"

TransactionManager::TransactionManager()
{
}

TransactionManager::~TransactionManager()
{
}

bool TransactionManager::performTransaction(Transaction * t, CustomerAccounts
	& accounts, BinTree<Item>& inventory)
{

	if (t->getIdentifier() == 'I')
	{
		cout << inventory;
		return true;
	}
	else if (t->getIdentifier() == 'H')
	{
		HistoryTransaction * historyTransaction = dynamic_cast<HistoryTransaction*>(t);
		return History(historyTransaction, accounts);
	}
	else if (t->getIdentifier() == 'B')
	{
		BorrowTransaction * borrowTransaction = dynamic_cast<BorrowTransaction*>(t);
		return Borrow(borrowTransaction, inventory, accounts);
	}
	else if (t->getIdentifier() == 'R')
	{
		ReturnTransaction * returnTransaction = dynamic_cast<ReturnTransaction*>(t);
		return Return(returnTransaction, inventory, accounts);
	}
	return false;
}

bool TransactionManager::History(HistoryTransaction *t, CustomerAccounts 
	& accounts)
{
	Customer *account = accounts.getCustomer(t->getCustomerId());
	if (account == NULL)
	{
		cerr << "Account " << t->getCustomerId() << "could not be found." << endl;
		return false;
	}
	account->printHistory();
	return true;
}

bool TransactionManager::Borrow(BorrowTransaction * t, BinTree<Item>&
	inventory, CustomerAccounts & accounts)
{
	Customer *account = accounts.getCustomer(t->getCustomerId());
	Item *item = NULL;
	if (account == NULL)
	{
		cerr << "Account " << t->getCustomerId() << "could not be found." << endl;
		return false;
	}
	if (!inventory.retrieve(t->getItemData(), item))
	{
		cerr << "Could not execute Borrow transaction: " << *t << endl;
		return false;
	}
	return true;
}

bool TransactionManager::Return(ReturnTransaction * t, BinTree<Item>&
	inventory, CustomerAccounts & accounts)
{
	return false;
}
