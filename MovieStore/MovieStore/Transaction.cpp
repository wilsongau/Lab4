#include "Transaction.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Transaction
// ----------------------------------------------------------------------------
Transaction::Transaction()
{
	identifier = 'T';
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Transaction
// ----------------------------------------------------------------------------
Transaction::~Transaction()
{
}

bool Transaction::initialize(const string &cmd)
{
	stringstream stream;
	stream << cmd;
	stream >> identifier;
	return true;
}

char Transaction::getIdentifier() const
{
	return identifier;
}

Transaction & Transaction::operator=(const Transaction &other)
{
	if (this != &other)
	{
		identifier = other.identifier;
	}
	return *this;
}

//bool Transaction::loadString(const string & cmd)
//{
//	//sample cmd: B 8000 D F National Lampoon's Animal House, 1978 || B 8888 D C 3 1971 Ruth Gordon
//
//	char readTransaction;
//	string temp;                // hold info about line
//	int customer_id;            // hold customer id
//
//	stringstream ss;            // string reader
//	ss << cmd;
//	ss >> readTransaction; //either B or R
//	ss >> customer_id;          // get customer id
//
//								//I think we should validate customer here, basically 
//								//if(!isExistingCustomer(customer_id)) 
//								//{
//								//do nothing or display message for bad line input
//								//}
//	char movietype;
//	char mediatype;
//	string temp1;
//	string temp2;
//	string majorActor;
//	int readYear = 0;
//	int readMonth = 0;
//
//	ss >> mediatype;                     // insert media tye                
//
//	if (mediatype == 'D')               // check if media type is valid
//	{
//		ss >> movietype;                 // insert movie type
//		switch (movietype)
//		{
//		case 'D': //Drama, string left to be read: "Steven Spielberg, Bogus Title,"
//			getline(ss, temp2, ',');     // insert  director
//			getline(ss, temp1, ',');     // insert title
//										 //parsed completed, we read: readTransaction, customer_id, mediatype, movietype, temp2 as director, temp1 as title
//			break;
//
//		case 'F': //Comedy, string left to be read: "National Lampoon's Animal House, 1978"
//			getline(ss, temp2, ',');    // insert title
//			getline(ss, temp1);         // hold year
//			stringstream(temp1) >> readYear;  // assign  year
//											  //parsed completed, we read: readTransaction, customer_id, mediatype, movietype, temp2 as title, readYear
//			break;
//
//		case 'C': //Classic, string left to be read: "3 1971 Ruth Gordon"
//			getline(ss, temp1, ' ');     // hold space
//			getline(ss, temp1, ' ');     // hold month
//			stringstream(temp1) >> readMonth; // assign month
//			getline(ss, temp1, ' ');     // hold year
//			stringstream(temp1) >> readYear;   // assingn year
//			ss >> temp1;                 // get first name
//			majorActor = temp1;
//			majorActor += ' ';
//			ss >> temp1;                 // get last name
//			majorActor += temp1;
//			//parsed completed, we read: readTransaction, customer_id, mediatype, movietype, readMonth, readYear, majorActor
//			break;
//
//		default: // invalid movie type
//				 //error handling
//			break;
//		}
//	}
//	// not DVD 
//	else
//	{
//		//error handling
//	}
//}

bool Transaction::is_number(const string & s) const
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	{
		++it;
	}
	return (!s.empty() && it == s.end());
}

