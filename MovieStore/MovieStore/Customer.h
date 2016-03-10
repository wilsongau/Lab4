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

#include <string>
#include <vector>
#include "LinkedList.hpp"
#include "Transaction.h"
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

	// Returns customer's first name
	string getFirstName() const;

	// Returs customer's last name
	string getLastName() const;

	//prints customer's transcation history
	void printHistory() const;

	// get the hashString for the customer
	string getHashString() const;

	bool addTransaction(Transaction * trans); // add transaction

private:
	int id;// customer ID
	string firstName, lastName;// string of customer first and last name
	LinkedList<Transaction> transactionHistory; // Link list of transcations
};