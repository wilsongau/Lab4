#include "Item.h"

Item::Item()
{
	stock = 0;
	identifier = 'I';
	name = "";
}

Item::Item(char id, int num, const string &name)
{
	identifier = id;
	stock = num;
	this->name = name;
}

Item::~Item()
{
}

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

char Item::getIdentifier() const
{
	return identifier;
}

int Item::getStock() const
{
	return stock;
}

void Item::setStock(int quantity)
{
	stock = quantity;
}

string Item::getName() const
{
	return name;
}

void Item::setName(const string &n)
{
	name = n;
}


