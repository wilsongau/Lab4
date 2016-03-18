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
#include "ReturnTransaction.h"
#include "Item.h"
class BorrowTransaction : public Transaction
{
	// output stream override
	friend ostream& operator<<(ostream &out,
		const BorrowTransaction &transaction);
public:
	BorrowTransaction(); // default constructor
	~BorrowTransaction(); // deconstructor
	int getCustomerId() const; // get customerID
	char getIdentifier() const;
	char getMediaType() const;  // get media type of the item being borrowed
	char getItemType() const; // get identifier of item type being borrowed
	string getSearchData() const; // retrieves the item's data
	string getTitle() const;
	string getDirector() const;
	string getActor() const;
	void setActor(const string &);
	int getYear() const;
	int getMonth() const;
	bool getCheckedOut() const; // checks if transaction is currently on loan
	void setCheckedOut(bool value); // set checked out
	bool Return(const ReturnTransaction &t);
	bool initialize(const string &);
	Item getItem() const;
	void setItem(Item *);
	BorrowTransaction& operator=(const BorrowTransaction &);
private:
	int customerId;
	char mediaType;
	char itemType;
	string title;
	int year;
	int month;
	string director;
	string actor;
	//string itemData; //what is itemData? the movie title to search for
	char identifier = 'B';
	bool checkedOut = true;
	Item * item;
};


#endif
//overriden bool Process()
//{
//	calls item->Borrow();
//}