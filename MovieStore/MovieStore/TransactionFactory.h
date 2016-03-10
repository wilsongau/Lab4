// ---------------------- TranscationFactory Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Static class using the factory design pattern which will create Transaction
// objects depending on the criteria contained in the parameter's command
// string.
// ---------------------------------------------------------------------------

#include "Transaction.h"
#include "BorrowTransaction.h"
#include "ReturnTransaction.h"
#include "InventoryTransaction.h"
#include "HistoryTransaction.h"
static class TransactionFactory
{
	enum TransactionType
	{
		I,
		H,
		B,
		R
	};
public:
	static Transaction*& MakeTransaction(string command);
};

//Transaction*& TransactionFactory::MakeTransaction(string command)
//{
	// Get command type
	// if type == TransactionType::{TYPE}
	//		split command into chunks according to the type.
	//		create Transaction object, and return it 
//}