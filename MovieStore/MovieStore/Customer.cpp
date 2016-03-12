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
	for (int i = 0; i < (int)transactionHistory.size(); i++) 
	{
		//delete transactionHistory[i];	 //I don't know if I need this
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

string Customer::getHashString() const
{
	string hs = firstName + lastName + to_string(id);
}

bool Customer::addTransaction(Transaction * trans)
{
	transactionHistory.push_back(trans);
}

bool Customer::operator==(const Customer& other) const 
{
	return (id == other.id);
}

bool Customer::operator!=(const Customer& other) const
{
	return (id != other.id);
}