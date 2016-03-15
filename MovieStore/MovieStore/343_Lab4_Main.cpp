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

int main()
{
	static const int inputFileCount = 3;
	string line = "";
	string filenames[inputFileCount] = { "data4movies.txt", "data4customers.txt",
		"data4commands.txt" };
	Store store;
	FileReader reader;
	for (unsigned int i = 0; i < inputFileCount; i++)
	{
		reader.setFileName(filenames[i]);
		while (reader.getNextLine(line))
		{
			store.ReadAction(line);
		}
	}

	return 0;
}