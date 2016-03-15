// ---------------------- TransactionManager Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 3/11/2016
// ---------------------------------------------------------------------------
// Takes in Transactions and processes them according to the transaction's
// specific identifier value.
// ---------------------------------------------------------------------------
#ifndef TRANSACTION_MANAGER_HEADER
#define TRANSACTION_MANAGER_HEADER
#include "Transaction.h"
#include "HistoryTransaction.h"
#include "BorrowTransaction.h"
#include "InventoryTransaction.h"
#include "ReturnTransaction.h"
#include "CustomerAccounts.h"
#include "Item.h"
#include "bintree.hpp"
#include <iostream>
using namespace std;
class TransactionManager
{
public:
	TransactionManager();
	~TransactionManager();
	bool performTransaction(Transaction * t, CustomerAccounts &accounts, 
		BinTree<Item> &items);  // switch selection for transaction type
private:
	// print transaction history for a particular account
	bool History(HistoryTransaction *t, 
		const CustomerAccounts &accounts);

	// borrow an item from the store
	bool Borrow(BorrowTransaction *t, BinTree<Item> &inventory, 
		CustomerAccounts &accounts);

	// return an item to the store
	bool Return(ReturnTransaction *t, BinTree<Item> &inventory, 
		CustomerAccounts &accounts);
};

#endif