// ---------------------- BorrowTransaction Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// Inherits from: Transaction
// Header file for the BorrowTransaction Class.  Contains data from for a
// transaction with the 'B' identifier.
// Inherited Process(): decrements the stock of the associated Item only if
// the following conditions are met: sufficient stock available and the 
// customerId is valid.  If the transaction can be processed, this transaction
// will be added to the customer's transaction history.
// ---------------------------------------------------------------------------
#ifndef BORROW_HEADER
#define BORROW_HEADER
#include "Transaction.h"
class BorrowTransaction : public Transaction
{
	// output stream override
	friend ostream& operator<<(ostream &out,
		const BorrowTransaction &transaction);
public:
	BorrowTransaction(); // default constructor
	BorrowTransaction(const string &cmd); // string constructor
	~BorrowTransaction(); // deconstructor
	int getCustomerId() const; // get customerID
	char getMediaType() const;  // get media type of the item being borrowed
	char getItemType() const; // get identifier of item type being borrowed
	string getItemData() const; // retrieves the item's data
	void setItemData(const string &);
	bool getCheckedOut() const; // checks if transaction is currently on loan
	void setCheckedOut(bool value); // set checked out

private:
	int customerId;
	char mediaType;
	char itemType;
	string itemData;
	char identifier = 'B';
	bool checkedOut;
};


#endif
//overriden bool Process()
//{
//	calls item->Borrow();
//}