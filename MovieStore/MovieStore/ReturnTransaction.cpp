#include "ReturnTransaction.h"

ReturnTransaction::ReturnTransaction()
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
