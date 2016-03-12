// ---------------------- HistoryTransaction Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Inherits from: Transaction
// Header file for the HistoryTransaction Class.  Contains data from for a
// transaction with the 'H' identifier.
// Inherited Process(): prints out the associated transactions with the
// customer account with the id value of customerId.
// ---------------------------------------------------------------------------
#include "Transaction.h"
class HistoryTransaction : Transaction
{
	// output steam override
	friend ostream& operator<<(ostream &out,
		const HistoryTransaction &transaction);

	// input stream override
	friend istream& operator>>(istream &in, HistoryTransaction &transaction);
public:
	HistoryTransaction(); // default constructor
	~HistoryTransaction(); // deconstructor
	int getCustomerId() const; // gets the customer's id number 
private:
	char identifier = 'H';
	int customerId;
};

//overriden bool Process()
//{
//	calls customer->history.PrintList();
//}