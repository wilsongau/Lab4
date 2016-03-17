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
#include <sstream>
#include <string>
using namespace std;
class Transaction
{
public:
	Transaction(); //default constructor
	~Transaction(); //deconstructor
	virtual bool initialize(const string&);
	virtual char getIdentifier() const; // returns the identifier of child class type
	virtual Transaction& operator=(const Transaction &);
protected:
	//bool loadString(const string&);
	bool is_number(const string&) const;
private:
	char identifier;
};
#endif