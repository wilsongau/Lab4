// ---------------------- Customer Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Holds customer data including the customer's ID number, first name, last
// name, and a link list containing transaction history associated with the 
// customer's account.
// ----------
#ifndef CUSTOMER_HEADER
#define CUSTOMER_HEADER
#include <string>
#include <vector>
#include "LinkedList.hpp"
#include "Item.h"
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "ReturnTransaction.h"
#include <iostream>

using namespace std;

class Customer

{
	friend ostream& operator<<(ostream &out, const Customer &customer);
	friend istream& operator>>(istream &in, Customer &customer);

public:
	Customer();	// Default Construct

	// Constructs a new customer based on parameters
	Customer(int, string, string); 
	~Customer();

	// Returns the customer Id
	int getId() const;
	void setId(int id);

	// Returns customer's first name
	string getFirstName() const;

	// Returs customer's last name
	string getLastName() const;

	//prints customer's transcation history
	void printHistory() const;

	// get the hashString for the customer
	string getHashString() const;

	bool addTransaction(Transaction * trans); // add transaction
	bool returnItem(const ReturnTransaction &); // returns an item
	bool addTransaction(const Transaction *); // add transaction


	bool operator==(const Customer& ) const;
	bool operator!=(const Customer& ) const;

private:
	int id;// customer ID
	string firstName, lastName;// string of customer first and last name
	vector<Transaction*> transactionHistory; // vector of transcations
};

#endif