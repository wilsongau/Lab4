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
