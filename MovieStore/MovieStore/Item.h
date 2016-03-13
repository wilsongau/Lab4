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
	Item(const string &cmd);
	Item(char id, int stock, const string &name);
	~Item();
	Item& operator=(const Item &);
	//will be overridden by children classes to be handled 
	//differently based on genre
	bool Borrow(HashTable<Item> *inventory);
	/*	PSEUDO CODE

		if stock > 0
			stock -= 1
		else
			if classic movie
				item* temp=NULL;
				temp = find related movies in inventory if possible
				if temp != NULL
					temp.stock -=1
			else
				return false
	*/

	//
	bool Return(Customer &customer);
	/*
		find if there is a borrowed Item that hasen't been 
		returned by the customer parameter

		if there is
			add one to stock, update customer transaction list
		if there is not
			return false
	*/

	//returns the unique identifier associated with the item
	char getIdentifier() const;

	//returns the quantity of this item that the store contains
	int getStock() const;

	//sets the stock of this item when someone borrows or returns a quantity
	void setStock(int);

	string getName() const;
	void setName(const string &);

private:
	//the amount of an item that the store contains
	int stock;

	//the unique identifier for an item
	char identifier;

	//name of the item
	string name;
};

