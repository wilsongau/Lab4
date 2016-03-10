#ifndef TRANSACTION_H
#define TRANSACTION_H
// ---------------------- Transaction Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Header file for the pure virtual Transaction Class.  Class will contain
// transaction data and a method for processing the transaction.
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
class Transaction
{
	friend ostream& operator<<(ostream &out, const Transaction &transaction);
	friend istream& operator>>(istream &in, Transaction &transaction);
public:
	Transaction(); //default constructor
	~Transaction(); //deconstructor
					
	virtual char getIdentifier() const = 0; // returns the identifier of child class type
	
	virtual bool Process() = 0; // pure virtual.  processes the transaction within the store.
};
#endif