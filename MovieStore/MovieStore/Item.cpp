#include "Item.h"

// ----------------------------------------------------------------------------
//	operator overload
//  overload operator<<
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Item &item) 
{
	out << item.name;
	return out;
}

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Item
// ----------------------------------------------------------------------------
Item::Item()
{
	stock = 0;
	identifier = 'I';
	name = "";
}



// ----------------------------------------------------------------------------
//	constructor
//  string constructor used for searching in bintree
// ----------------------------------------------------------------------------
Item::Item(const string & cmd)
{
	stock = 0;
	identifier = 'I';
	name = cmd;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Item
// ----------------------------------------------------------------------------
Item::~Item()
{
	stock = 0;
	identifier = 'I';
	name = "";
}

void Item::setIdentifier(char id)
{
	identifier = id;
}

Item & Item::operator=(const Item & other)
{
	stock = other.getStock();
	identifier = other.getIdentifier();
	name = other.getName();
	return *this;
}

bool Item::operator==(const Item &compare) const
{
	if (this->name == compare.getName())
	{
		return true;
	}
	return false;
}

bool Item::operator!=(const Item &compare) const
{
	return !operator==(compare);
}

bool Item::operator<(const Item & other) const
{
	if (this->name < other.getName())
	{
		return true;
	}
	return false;
}

bool Item::operator<=(const Item &other) const
{
	return !operator>(other);
}

bool Item::operator>(const Item &other) const
{
	if (this->name > other.getName())
	{
		return true;
	}
	return false;
}

bool Item::operator>=(const Item &other) const
{
	return !operator<(other);
}

bool Item::initialize(const string & cmd)
{
	return false;
}

// ----------------------------------------------------------------------------
//	Borrow(HashTable<Item>*)
//  Reduce the stock if available, then return true. Will be overridden by 
//  children classes possibly handled  differently based on genre
// ----------------------------------------------------------------------------
bool Item::Borrow()
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

// ----------------------------------------------------------------------------
//	Return(Customer &)
//  checked if the movies was rented by the customer, if so update stock and
//  customer's history.
// ----------------------------------------------------------------------------
bool Item::Return()
{
	stock++;
	return true;
}

// ----------------------------------------------------------------------------
//	getIdentifier()
//  return the identifier of the item
// ----------------------------------------------------------------------------

char Item::getIdentifier() const
{
	return identifier;
}

// ----------------------------------------------------------------------------
//	getStock()
//  return the stock of the item
// ----------------------------------------------------------------------------
int Item::getStock() const
{
	return stock;
}


// ----------------------------------------------------------------------------
//	setStock(int)
//  set the stock of the item
// ----------------------------------------------------------------------------
void Item::setStock(int quantity)
{
	stock = quantity;
}


// ----------------------------------------------------------------------------
//	getName()
//  return the name of the item
// ----------------------------------------------------------------------------
string Item::getName() const
{
	return name;
}

// ----------------------------------------------------------------------------
//	setName(const string&)
//  set the name of the item
// ----------------------------------------------------------------------------
void Item::setName(const string &n)
{
	name = n;
}
