#include "ReturnTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class CustomerAccounts
// ----------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction()
{

}

// ----------------------------------------------------------------------------
//	constructor
//  string constructor for class CustomerAccounts
// ----------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction(const string & cmd)
{
	loadString(cmd);
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