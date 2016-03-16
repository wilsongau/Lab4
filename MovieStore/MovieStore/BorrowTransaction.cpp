#include "BorrowTransaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class BorrowTransaction
// ----------------------------------------------------------------------------
BorrowTransaction::BorrowTransaction()
{
}

// ----------------------------------------------------------------------------
//	constructor
//  string constructor for class BorrowTransaction
// ----------------------------------------------------------------------------
BorrowTransaction::BorrowTransaction(const string & cmd)
{
	loadString(cmd);
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
//	setItemData()
//  set the item's data
// ----------------------------------------------------------------------------
void BorrowTransaction::setItemData(const string &data)
{
	itemData = data;
}


// ----------------------------------------------------------------------------
//	getCheckedOut()
//  return true if transaction is currently on loan
// ----------------------------------------------------------------------------
bool BorrowTransaction::getCheckedOut() const
{
	return checkedOut;
}


// ----------------------------------------------------------------------------
//	setCheckedOut(bool)
//  set checked out
// ----------------------------------------------------------------------------
void BorrowTransaction::setCheckedOut(bool value)
{
	checkedOut = value;
}
// ----------------------------------------------------------------------------
//  operator<<
//  output stream operator
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const BorrowTransaction &transaction)
{
	out << "customer: " << transaction.customerId << " borrowed: " 
		<< transaction.itemData;
	if (!transaction.checkedOut)
	{
		out << " NOT RETURNED";
	}
	return out;
}
