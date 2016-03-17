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
#ifndef ACCOUNTS_HEADER
#define ACCOUNTS_HEADER
#include "HashTable.hpp"
#include "Customer.h"
#include <istream>
class CustomerAccounts
{
public:
	//construct customer account
	CustomerAccounts();
	~CustomerAccounts();

	// get customer by hashString
	Customer* getCustomer(int);

	// Insert customer command
	bool Insert(const string &command);
private:
	// Holds a hashTable of customers
	HashTable<Customer> customers;
};

#endif