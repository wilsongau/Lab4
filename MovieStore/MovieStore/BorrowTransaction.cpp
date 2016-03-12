#include "BorrowTransaction.h"

BorrowTransaction::BorrowTransaction()
{
}

BorrowTransaction::~BorrowTransaction()
{
}

int BorrowTransaction::getCustomerId() const
{
	return customerId;
}

char BorrowTransaction::getMediaType() const
{
	return mediaType;
}

char BorrowTransaction::getItemType() const
{
	return itemType;
}

string BorrowTransaction::getItemData() const
{
	return itemData;
}

bool BorrowTransaction::getCheckedOut() const
{
	return false;
}

void BorrowTransaction::setCheckedOut(bool value)
{
}

bool BorrowTransaction::findItem(HashTable<Item>* inventory) const
{
	return false;
}
