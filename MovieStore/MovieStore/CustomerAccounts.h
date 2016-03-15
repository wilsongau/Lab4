// ---------------------- CustomerAccounts Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 28, 2016
// Modified 2/28/2016
// ---------------------------------------------------------------------------
// This class cunstruct the customer account Insert function which determines
//if a customer is already in the system or not
// HashTable<Customer> wrapper which checks for duplicate accounts when
// a new account is inserted.
// ---------------------------------------------------------------------------

#include "HashTable.hpp"
#include "Customer.h"
class CustomerAccounts
{
public:
	//construct customer account
	CustomerAccounts();
	~CustomerAccounts();

	// get customer by hashString
	Customer* getCustomer(const string &hashstring) const;

	// Insert customer command
	bool Insert(const string &command);
private:
	// Holds a hashTable of customers
	HashTable<Customer> customers;

	//check for the duplicate customers
	//	will be called internally in the insert function
	bool checkForDuplicates(const Customer &account) const;
};
