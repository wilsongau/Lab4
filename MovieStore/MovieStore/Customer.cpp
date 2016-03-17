#include "Customer.h"
// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Customer
// ----------------------------------------------------------------------------
Customer::Customer()
{
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class Customer
// ----------------------------------------------------------------------------
Customer::Customer(int idIn, string firstNameIn, string lastNameIn)
{
	firstName = firstNameIn;
	lastName = lastNameIn;
	id = idIn;
}


// ----------------------------------------------------------------------------
//	destructor
//  default constrdestructoructor for class Customer
// ----------------------------------------------------------------------------
Customer::~Customer()
{
	for (int i = 0; i < (int)transactionHistory.size(); i++) 
	{
		//delete transactionHistory[i];	 //I don't know if I need this
	}
}


// ----------------------------------------------------------------------------
//	getId()
//  return the customer id
// ----------------------------------------------------------------------------

int Customer::getId() const
{
	return id;
}


// ----------------------------------------------------------------------------
//	setId()
//  set the customer id
// ----------------------------------------------------------------------------

void Customer::setId(int id)
{
	this->id = id;
}


//----------------------------------------------------------------------------
//	getFirstName()
//  return customer's first name
// ----------------------------------------------------------------------------

string Customer::getFirstName() const
{
	return firstName;
}

// ----------------------------------------------------------------------------
//	getLastName()
//  return customer's last name
// ----------------------------------------------------------------------------
string Customer::getLastName() const
{
	return lastName;
}

// ----------------------------------------------------------------------------
// printHistory()
// prints customer's transcation history
// ----------------------------------------------------------------------------
void Customer::printHistory() const
{
	vector <string> print_array;
	cout << endl;
	cout << "=============================================================================" << endl;
	cout << "Name: " << getFirstName() << " " << getLastName() << ", ID: " << getId() << endl;
	cout << "History:" << endl;

	int size = transactionHistory.size();
	if (size > 0) 
	{
		for (int i = 0; i < size; i++) 
		{			
			/*if (*(transactionHistory[i]).getIdentifier() == 'B')
			{
				cout << "Borrow ";
			}
			else
			{
				cout << "Return ";
			}
			cout << *(transactionHistory[i]).getItem() << endl;	*/	
		}
		cout << endl;
	}
	else 
	{
		cout << "No Transactions for Customer" << endl;
	}
	
	cout << "=============================================================================" << endl;
	cout << endl;
}

// ----------------------------------------------------------------------------
//	getHashString
//  get the hashString for the customer
// ----------------------------------------------------------------------------
string Customer::getHashString() const
{
	return to_string(getId());
}

// ----------------------------------------------------------------------------
//	addTransaction(Transaction*)
//  add transaction
// ----------------------------------------------------------------------------
bool Customer::addTransaction(Transaction * trans)
{
	transactionHistory.push_back(trans);
	return true;
}

bool Customer::returnItem(const string & name)
{
	return false;
}

// ----------------------------------------------------------------------------
//	operator==
//  overload operator ==
// ----------------------------------------------------------------------------

bool Customer::operator==(const Customer& other) const 
{
	return (id == other.id);
}

// ----------------------------------------------------------------------------
//	operator !=
//  overload operator !=
// ----------------------------------------------------------------------------
bool Customer::operator!=(const Customer& other) const
{
	return (id != other.id);
}
