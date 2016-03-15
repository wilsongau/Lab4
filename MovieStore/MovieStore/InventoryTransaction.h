// ---------------------- InventoryTransaction Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// Inherits from: Transaction
// Header file for the InventoryTransaction Class.  Contains data from for a
// transaction with the 'I' identifier.
// Inherited process() will display the current inventory in the store.
// ---------------------------------------------------------------------------
#ifndef INVENTORY_HEADER
#define INVENTORY_HEADER
#include "Transaction.h"
class InventoryTransaction : public Transaction
{
	// output stream override
	friend ostream& operator<<(ostream &out, const InventoryTransaction &transaction);
public:
	InventoryTransaction(); // default constructor
	InventoryTransaction(const string &cmd); // string constructor
	~InventoryTransaction(); // deconstructor

private:
	char identifier = 'I';
};

//overriden bool Process()
//{
//	calls inventory.PrintHashTable();
//}
#endif