// ---------------------- Item Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Header file for the Item Class.  Contains the stock quantity, Item type
// identifier, release year, and title of an item.
// ---------------------------------------------------------------------------

#include <string>
#include <iostream>
#include "HashTable.hpp"
#include "Customer.h"
using namespace std;
class Item
{
	//overloads for printing or entering an item 
	friend ostream& operator<<(ostream &out, const Item &item);
	friend istream& operator>>(istream &out, Item &item);

public:
	Item();
	~Item();

	//will be overridden by children classes to be handled 
	//differently based on genre
	virtual bool Borrow(HashTable<Item> *inventory);

	bool Return(Customer &customer);
	
	//returns a string that is used in the hashing function of a hash table
	virtual string getHashString() const;

	//returns the unique identifier associated with the item
	char getIdentifier() const;

	//returns the quantity of this item that the store contains
	int getStock() const;

	//sets the stock of this item when someone borrows or returns a quantity
	void setStock(int);

private:
	//the amount of an item that the store contains
	int stock;

	//the unique identifier for an item
	char identifier;
};