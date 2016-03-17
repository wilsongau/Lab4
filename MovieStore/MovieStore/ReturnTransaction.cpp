#include "ReturnTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class CustomerAccounts
// ----------------------------------------------------------------------------
ReturnTransaction::ReturnTransaction()
{

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
//	initialize
//  initialize the transaction with data parsed from the string
// ----------------------------------------------------------------------------
bool ReturnTransaction::initialize(const string & cmd)
{
	return false;
}

ReturnTransaction & ReturnTransaction::operator=(const ReturnTransaction &other)
{
	if (this != &other)
	{
		identifier = other.identifier;
		customerId = other.customerId;
		mediaType = other.mediaType;
		itemType = other.itemType;
	}
	return *this;
}
