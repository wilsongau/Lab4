#include "Item.h"

//overloads for printing an item
ostream& operator<<(ostream &out, const Item &item) 
{}

// overload for entering an item 
istream& operator>>(istream &out, Item &item) 
{}

//default constructor
Item::Item()
{
}

//default destructor
Item::~Item()
{
}


bool Item::Borrow(HashTable<Item>* inventory)
{
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
	return false;
}


bool Item::Return(Customer & customer)
{
	/*
	find if there is a borrowed Item that hasen't been
	returned by the customer parameter

	if there is
	add one to stock, update customer transaction list
	if there is not
	return false
	*/
	return false;
}

string Item::getHashString() const
{
	return string();
}

char Item::getIdentifier() const
{
	return identifier;
}

int Item::getStock() const
{
	return stock;
}

void Item::setStock(int)
{
}
