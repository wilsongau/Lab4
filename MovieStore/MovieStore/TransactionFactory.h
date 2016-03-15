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
class TransactionFactory
{
public:
	Transaction*& MakeTransaction(string command);
};
