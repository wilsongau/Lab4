<<<<<<< HEAD
#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(int idIn, string firstNameIn, string lastNameIn)
{
	firstName = firstNameIn;
	lastName = lastNameIn;
	id = idIn;
}

Customer::~Customer()
{
	if (!transactionHistory.isEmpty())
	{
		transactionHistory.DeleteList();
	}
}

int Customer::getId() const
{
	return id;
}

string Customer::getFirstName() const
{
	return firstName;
}

string Customer::getLastName() const
{
	return lastName;
}

void Customer::printHistory() const
{
	vector <string> print_array;

	cout << endl;
	cout << "=============================================================================" << endl;
	cout << "Name: " << getFirstName() << " " << getLastName << ", ID: " << getId() << endl;
	cout << "History:" << endl;
	LinkedList<Transaction> *current = transactionHistory->pHead; //not this way, but I hope you know what I mean
	// traverse linkd list
	while (current != NULL)
	{   // insert info into vector
		if (current->pData->getIdentifier() == 'B') 
		{
			print_array.push_back("Borrow" + "WHATEVER DATA HERE");
		}
		else 
		{
			print_array.push_back("Return" + "WHATEVER DATA HERE");
		}
		current = current->pNext;
	}

	vector<string>::reverse_iterator it; // print the history from the earliest to oldest
	for (it = print_array.rbegin(); it != print_array.rend(); ++it) 
	{
		cout << *it << endl;          // print history
	}
	cout << "=============================================================================" << endl;
	cout << endl;
}

string Customer::getHashString() const
{
	string hs = firstName + lastName + to_string(id);
}

bool Customer::addTransaction(Transaction * trans)
{
	transactionHistory.Insert(trans);
}

bool Customer::returnItem(const Item & item)
{
	return false;
}
=======
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
	cout << endl;
	cout << "=============================================================================" << endl;
	cout << "Name: " << getFirstName() << " " << getLastName << ", ID: " << getId() << endl;
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
	string hs = firstName + lastName + to_string(id);
}

// ----------------------------------------------------------------------------
//	addTransaction(Transaction*)
//  add transaction
// ----------------------------------------------------------------------------
bool Customer::addTransaction(Transaction * trans)
{
	transactionHistory.push_back(trans);
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
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
