// ---------------------- MovieStoreDriver.cpp ------------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/28/2016
// ---------------------------------------------------------------------------
// contains main() for the Movie Store application.
// ---------------------------------------------------------------------------
#include "Store.h"
#include "FileReader.h"
using namespace std;

InventoryTransaction::InventoryTransaction()
{
}

InventoryTransaction::InventoryTransaction(const string & cmd)
{
	string readTransaction;
	stringstream ss;
	ss << cmd;
	getline(ss, readTransaction);
}

InventoryTransaction::~InventoryTransaction()
{
}
