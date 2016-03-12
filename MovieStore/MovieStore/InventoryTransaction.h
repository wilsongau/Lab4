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
#include "Transaction.h"
class InventoryTransaction : Transaction
{
	// output stream override
	friend ostream& operator<<(ostream &out, const InventoryTransaction &transaction);

	//input stream override
	friend istream& operator>>(istream &in, InventoryTransaction &transaction);
public:
	InventoryTransaction(); // default constructor
	~InventoryTransaction(); // deconstructor

private:
	char identifier = 'I';
};

//overriden bool Process()
//{
//	calls inventory.PrintHashTable();
//}