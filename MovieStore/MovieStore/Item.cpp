#include "Item.h"

// ----------------------------------------------------------------------------
//	operator overload
//  overload operator<<
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Item &item) 
{
	out << item.name << ": " << item.stock;
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

Item::Item(const string & cmd)
{
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class Item
// ----------------------------------------------------------------------------
Item::Item(char id, int num, const string &name)
{
	identifier = id;
	stock = num;
	this->name = name;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Item
// ----------------------------------------------------------------------------
Item::~Item()
{
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
	if (this->name == compare.getName() && 
		this->stock == compare.getStock() && 
		this->identifier == compare.getIdentifier())
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
	if (this->identifier < other.getIdentifier())
	{
		return true;
	}
	if (this->identifier == other.getIdentifier() &&
		this->name < other.getName())

	{
		return true;
	}
	if (this->identifier == other.getIdentifier() &&
		this->name == other.getName() &&
		this->stock < other.getStock())

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
	if (this->identifier > other.getIdentifier())
	{
		return true;
	}
	if (this->identifier == other.getIdentifier() &&
		this->name > other.getName())

	{
		return true;
	}
	if (this->identifier == other.getIdentifier() &&
		this->name == other.getName() &&
		this->stock > other.getStock())

	{
		return true;
	}
	return false;
}

bool Item::operator>=(const Item &other) const
{
	return !operator<(other);
}

// ----------------------------------------------------------------------------
//	Borrow(HashTable<Item>*)
//  Reduce the stock if available, then return true. Will be overridden by 
//  children classes possibly handled  differently based on genre
// ----------------------------------------------------------------------------
bool Item::Borrow(BorrowTransaction &t)
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
