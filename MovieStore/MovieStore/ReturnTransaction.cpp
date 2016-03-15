#include "ReturnTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class CustomerAccounts
// ----------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction()
{

}

ReturnTransaction::ReturnTransaction(const string & cmd)
{
}

ReturnTransaction::~ReturnTransaction()
{
}

int ReturnTransaction::getCustomerId() const
{
	return customerId;
}

char ReturnTransaction::getMediaType() const
{
	return mediaType;
}

char ReturnTransaction::getItemType() const
{
	return itemType;
}

string ReturnTransaction::getItemData() const
{
	return itemData;
}

bool ReturnTransaction::findItem(HashTable<Item>* inventory) const
{
	return false;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class ReturnTransaction
// ----------------------------------------------------------------------------
ReturnTransaction::~ReturnTransaction()
{
}

// ----------------------------------------------------------------------------
//	getCustomerId()
//  return the customer's id
// ----------------------------------------------------------------------------
int ReturnTransaction::getCustomerId() const
{
	return customerId;
}

// ----------------------------------------------------------------------------
//	getMediaType()
//  return media type of the item being returned
// ----------------------------------------------------------------------------
char ReturnTransaction::getMediaType() const
{
	return mediaType;
}

// ----------------------------------------------------------------------------
//	getItemType()
//  return identifier for the item type being returned
// ----------------------------------------------------------------------------
char ReturnTransaction::getItemType() const
{
	return itemType;
}

// ----------------------------------------------------------------------------
//	getItemData()
//  return the item's data string
// ----------------------------------------------------------------------------
string ReturnTransaction::getItemData() const
{
	return itemData;
}

// ----------------------------------------------------------------------------
//	findItem(HashTable<Item>*)
//  return true if found the item
// ----------------------------------------------------------------------------
bool ReturnTransaction::findItem(HashTable<Item>* inventory) const
{
	return false;
}