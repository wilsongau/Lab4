// ---------------------- ReturnTransaction Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// Inherits from: Transaction
// Header file for the Return Transaction Class.  Contains data from for a
// transaction with the 'R' identifier.
// Inherited Process(): calls the return() function of the contained movie and
// adds this object to the associated customer's transaction history if the 
// following conditions are satisfied: customerId is valid, item data is valid,
// associate customer (customerId) has a a related Borrow transaction that is
// currently checked out.
// ---------------------------------------------------------------------------
#include "Transaction.h"
#include "Item.h"
#include "HashTable.hpp"
class ReturnTransaction : public Transaction
{
	//output stream override
	friend ostream& operator<<(ostream &out,
		const ReturnTransaction &transaction);
public:
	ReturnTransaction(); //default constructor
	ReturnTransaction(const string &cmd);
	~ReturnTransaction(); //deconstructor
	int getCustomerId() const; // gets customer account id
	char getMediaType() const;  // gets media type of the item being returned
	char getItemType() const; // gets identifier for the item type being returned
	string getItemData() const; // gets the item's data string
	bool findItem(HashTable<Item> *inventory) const; // gets the item

private:
	int customerId;
	char mediaType;
	char itemType;
	string itemData;
	Item* item;
	char identifier = 'R';
};

//overriden bool Process()
//{
//	calls item->Return();
//}
