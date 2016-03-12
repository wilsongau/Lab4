#include "Item.h"

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	operator overload
//  overload operator<<
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Item &item) 
{}

// overload for entering an item 
// ----------------------------------------------------------------------------
//	operator overload
//  overload operator>>
// ----------------------------------------------------------------------------
istream& operator>>(istream &out, Item &item) 
{}

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
Item::Item()
{
	stock = 0;
	identifier = 'I';
	name = "";
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class Item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
Item::Item(char id, int num, const string &name)
{
	identifier = id;
	stock = num;
	this->name = name;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
Item::~Item()
{
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	Borrow(HashTable<Item>*)
//  Reduce the stock if available, then return true. Will be overridden by 
//  children classes possibly handled  differently based on genre
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
bool Item::Borrow(HashTable<Item>* inventory)
{
	if(stock <= 0)
	{ 
		return false;
	}
	else
	{
		stock--;
		return true;
	}
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	Return(Customer &)
//  checked if the movies was rented by the customer, if so update stock and
//  customer's history.
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
bool Item::Return(Customer & customer)
{
	if (customer.returnItem(name))
	{
		stock++;
		return true;
	}
	else
	{
		return false;
	}
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	getIdentifier()
//  return the identifier of the item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
char Item::getIdentifier() const
{
	return identifier;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	getStock()
//  return the stock of the item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
int Item::getStock() const
{
	return stock;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	setStock(int)
//  set the stock of the item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
void Item::setStock(int quantity)
{
	stock = quantity;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	getName()
//  return the name of the item
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
string Item::getName() const
{
	return name;
}

<<<<<<< HEAD
void Item::setName(const string &n)
{
	name = n;
}


=======
// ----------------------------------------------------------------------------
//	setName(const string&)
//  set the name of the item
// ----------------------------------------------------------------------------
void Item::setName(const string &n)
{
	name = n;
}
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
