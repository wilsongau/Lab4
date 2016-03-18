#include "TransactionManager.h"

TransactionManager::TransactionManager()
{
}

TransactionManager::~TransactionManager()
{
}

bool TransactionManager::performTransaction(Transaction * t, CustomerAccounts
	& accounts, BinTree<Item>& inventory, HashTable<ClassicMovie> &classics)
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
		return Borrow(borrowTransaction, inventory, accounts, classics);
	}
	else if (t->getIdentifier() == 'R')
	{
		ReturnTransaction * returnTransaction = dynamic_cast<ReturnTransaction*>(t);
		return Return(returnTransaction, inventory, accounts, classics);
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
	inventory, CustomerAccounts & accounts, HashTable<ClassicMovie> &classics)
{
	Customer *account = accounts.getCustomer(t->getCustomerId());
	Item *item = NULL;
	Item *target = NULL;
	if(account == NULL)
	{
		cerr << "Account " << t->getCustomerId() << "could not be found." << endl;
		return false;
	}
	if (t->getItemType() == 'C')
	{

		ClassicMovie *temp = new ClassicMovie;
		ClassicMovie *result = NULL;
		temp->setIdentifier(t->getItemType());
		temp->setReleaseMonth(t->getMonth());
		temp->setReleaseYear(t->getYear());
		temp->setStarringActor(t->getActor());
		string hash = to_string(temp->getReleaseMonth()) + to_string(temp->getReleaseYear()) + temp->getStarringActor();
		if (classics.get(hash, *temp, result));
		{
			cerr << "Could not execute Borrow transaction: " << *t << endl;
			return false;
		}
	}
	if (t->getItemType() == 'D')
	{
		DramaMovie *temp = new DramaMovie;
		temp->setIdentifier(t->getItemType());
		temp->setDirector(t->getDirector());
		(temp)->setName(t->getTitle());
		if (!inventory.retrieve(*temp, item))
		{
			cerr << "Could not execute Borrow transaction: " << *t << endl;
			return false;
		}
	}
	if (t->getItemType() == 'F')
	{
		ComedyMovie *temp = new ComedyMovie;
		temp->setIdentifier(t->getItemType());
		(temp)->setReleaseYear(t->getYear());
		(temp)->setName(t->getTitle());
		if (!inventory.retrieve(*temp, item))
		{
			cerr << "Could not execute Borrow transaction: " << *t << endl;
			return false;
		}
	}
	if (item->getIdentifier() == 'C')
	{
		if (item->Borrow())
		{
			account->addTransaction(t);
			return true;
		}
		else
		{
			ClassicMovie *temp = dynamic_cast<ClassicMovie*>(item);
			list<ClassicMovie*>::iterator iterator;
			for (iterator = temp->getRelated().begin(); iterator != temp->getRelated().end(); ++iterator)
			{
				if ((*iterator)->getStock() > 0)
				{
					(*iterator)->Borrow();
					t->setCheckedOut(true);
					t->setActor((*iterator)->getStarringActor());
					return true;
				}
			}
		}
	}
	if (item->Borrow())
	{
		account->addTransaction(t);
		return true;
	}
	return false;
}


bool TransactionManager::Return(ReturnTransaction * t, BinTree<Item>&
	inventory, CustomerAccounts & accounts, HashTable<ClassicMovie> &classics)
{
	Customer *account = accounts.getCustomer(t->getCustomerId());
	Item *item = NULL;
	Item *target = NULL;
	if (t->getItemType() == 'C')
	{

		ClassicMovie *temp = new ClassicMovie;
		ClassicMovie *result = NULL;
		temp->setIdentifier(t->getItemType());
		temp->setReleaseMonth(t->getMonth());
		temp->setReleaseYear(t->getYear());
		temp->setStarringActor(t->getActor());
		target = dynamic_cast<Item*>(temp);
		string hash = to_string(temp->getReleaseMonth()) + to_string(temp->getReleaseYear()) + temp->getStarringActor();
		if (classics.get(hash, *temp, result))
		{
			cerr << "Could not execute Borrow transaction: " << *t << endl;
			return false;
		}
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
	if (account->addTransaction(t))
	{
		item->Return();
		return true;
	}
	cerr << "Could not execute Borrow transaction: " << *t << endl;
	return false;
}
