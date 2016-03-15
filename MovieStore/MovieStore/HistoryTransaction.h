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
#ifndef HISTORY_HEADER
#define HISTORY_HEADER
#include "Transaction.h"
class HistoryTransaction : public Transaction
{
	// output steam override
	friend ostream& operator<<(ostream &out,
		const HistoryTransaction &transaction);
public:
	HistoryTransaction(); // default constructor
	HistoryTransaction(const string &cmd); // string constructor
	~HistoryTransaction(); // deconstructor
	int getCustomerId() const; // gets the customer's id number 
	HistoryTransaction& operator=(const HistoryTransaction &t);
private:
	char identifier = 'H';
	int customerId;
};

//overriden bool Process()
//{
//	calls customer->history.PrintList();
//}
#endif