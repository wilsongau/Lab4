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
	//sample cmd: R 8000 D F National Lampoon's Animal House, 1978 || R 8888 D C 3 1971 Ruth Gordon

	char readTransaction;
	string temp;                // hold info about line
	int read_customer_id;            // hold customer id
	string numCheckTemp;

	stringstream ss;            // string reader
	ss << cmd;
	ss >> readTransaction; //either B or R

	if (readTransaction != 'R' || readTransaction != 'r')
	{
		return false;
	}


	ss >> numCheckTemp;          // get customer id
	if (!is_number(numCheckTemp))
	{
		return false;
	}
	stringstream(numCheckTemp) >> read_customer_id;
	
	//I think we should validate customer here, basically 
	//if(!isExistingCustomer(customer_id)) 
	//{
	//	//display message for bad line input or anything
	//	return false;
	//}
	customerId = read_customer_id;
	char read_movietype;
	char read_mediatype;
	string temp1, read_director, read_title;
	string temp2;
	string read_majorActor;
	int read_Year = 0;
	int read_Month = 0;

	ss >> read_mediatype;                     // insert media tye                
	

	if (read_mediatype == 'D')               // check if media type is valid
	{
		mediaType = read_mediatype;
		ss >> read_movietype;                 // insert movie type
		itemType = read_movietype;
		switch (read_movietype)
		{
		case 'D': //Drama, string left to be read: "Steven Spielberg, Bogus Title,"
			getline(ss, read_director, ',');     // insert  director
			getline(ss, read_title, ',');     // insert title
			//parsed completed, we read: read_director, read_title
			//check if movie exist
			break;

		case 'F': //Comedy, string left to be read: "National Lampoon's Animal House, 1978"
			getline(ss, read_title, ',');    // insert title
			getline(ss, temp1);         // hold year
			stringstream(temp1) >> numCheckTemp;
			if (!is_number(numCheckTemp))
			{
				return false;
			}
			stringstream(temp1) >> read_Year;  // assign  year
			//parsed completed, we read: read_title, read_Year
			//check if movie exist
			break;

		case 'C': //Classic, string left to be read: "3 1971 Ruth Gordon"
			getline(ss, temp1, ' ');     // hold space
			getline(ss, temp1, ' ');     // hold month
			stringstream(temp1) >> numCheckTemp;
			if (!is_number(numCheckTemp))
			{
				return false;
			}
			stringstream(temp1) >> read_Month;  // assign  year
			getline(ss, temp1, ' ');     // hold year
			stringstream(temp1) >> numCheckTemp;
			if (!is_number(numCheckTemp))
			{
				return false;
			}
			stringstream(temp1) >> read_Year;  // assign  year
			ss >> temp1;                 // get first name
			read_majorActor = temp1;
			read_majorActor += ' ';
			ss >> temp1;                 // get last name
			read_majorActor += temp1;
			//parsed completed, we read: read_Month, read_Year, read_majorActor
			//check if movie exist
			break;

		default: // invalid movie type
			return false;
			break;
		}
	}
	else	// not DVD 
	{
		return false;
	}
	//movie exist, check if stock still available
	//reduce stock
	//return true
	//if no stock, check if its classic
	//if classic, check related movie
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
