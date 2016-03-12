#include "BorrowTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class BorrowTransaction
// ----------------------------------------------------------------------------
BorrowTransaction::BorrowTransaction()
{
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class BorrowTransaction
// ----------------------------------------------------------------------------
BorrowTransaction::~BorrowTransaction()
{
}

// ----------------------------------------------------------------------------
//	getCustomerId()
//  return customerId
// ----------------------------------------------------------------------------
int BorrowTransaction::getCustomerId() const
{
	return customerId;
}

// ----------------------------------------------------------------------------
//	getMediaType()
//  return media type of the item being borrowed
// ----------------------------------------------------------------------------
char BorrowTransaction::getMediaType() const
{
	return mediaType;
}

// ----------------------------------------------------------------------------
//	getItemType()
//  return identifier of item type being borrowed
// ----------------------------------------------------------------------------
char BorrowTransaction::getItemType() const
{
	return itemType;
}

// ----------------------------------------------------------------------------
//	getItemData()
//  return the item's data
// ----------------------------------------------------------------------------
string BorrowTransaction::getItemData() const
{
	return itemData;
}

// ----------------------------------------------------------------------------
//	getCheckedOut()
//  return true if transaction is currently on loan
// ----------------------------------------------------------------------------
bool BorrowTransaction::getCheckedOut() const
{
	return false;
}

// ----------------------------------------------------------------------------
//	setCheckedOut(bool)
//  set checked out
// ----------------------------------------------------------------------------
void BorrowTransaction::setCheckedOut(bool value)
{
}

// ----------------------------------------------------------------------------
//	findItem(HashTable<Item>*)
//  gets the item
// ----------------------------------------------------------------------------
bool BorrowTransaction::findItem(HashTable<Item>* inventory) const
{
	return false;
}
