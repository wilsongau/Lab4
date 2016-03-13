// ---------------------- Store Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// The Store class is the interface component of the program. It will
// route method calls and commands to the internal components of the
// application.
// ---------------------------------------------------------------------------

#include "HashTable.hpp"
#include "Item.h"
#include "CustomerAccounts.h"
#include "ItemFactory.h"
#include "bintree.hpp"
#include "TransactionFactory.h"
#include "TransactionManager.h"
const static string ITEM_IDENTIFIERS[] = { "F", "C", "D" };
const static string TRANSACTION_IDENTIFIERS[] = { "H", "B", "R", "I" };
class Store
{
public:
	
	Store();
	~Store();

	// Based on action will creates the customer list depending on the parameter's contents,
	//	route transactions to TransactionFactory, and items to ItemFactory 
	bool ReadAction(const string &action);
private:
	BinTree<Item> inventory; // Hash table of items
	CustomerAccounts accounts; // Wrapper object for Customers
	ItemFactory itemFactory;
	TransactionFactory transactionFactory;
	TransactionManager transactionManager;
};