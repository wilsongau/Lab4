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
	Item *target = NULL;
	if (t->getItemType() == 'C')
	{
		
		ClassicMovie *temp = new ClassicMovie;
		temp->setIdentifier(t->getItemType());
		temp->setReleaseMonth(t->getMonth());
		temp->setReleaseYear(t->getYear());
		temp->setStarringActor(t->getActor());
		target = dynamic_cast<Item*>(temp);
	}
	if (t->getItemType() == 'D')
	{
		DramaMovie *temp = new DramaMovie;
		temp->setIdentifier(t->getItemType());
		temp->setDirector(t->getDirector());
		(temp)->setName(t->getTitle());
		target = dynamic_cast<Item*>(temp);
	}
	if (t->getItemType() == 'F')
	{
		ComedyMovie *temp = new ComedyMovie;
		temp->setIdentifier(t->getItemType());
		(temp)->setReleaseYear(t->getYear());
		(temp)->setName(t->getTitle());
		target = dynamic_cast<Item*>(temp);
	}
	if (account == NULL)
	{
		cerr << "Account " << t->getCustomerId() << "could not be found." << endl;
		return false;
	}
	if (!inventory.retrieve(*target, item))
	{
		cerr << "Could not execute Borrow transaction: " << *t << endl;
		return false;
	}
	item->Borrow(*t);
	account->addTransaction(t);
	return true;
}

bool TransactionManager::Return(ReturnTransaction * t, BinTree<Item>&
	inventory, CustomerAccounts & accounts)
{
	return false;
}
