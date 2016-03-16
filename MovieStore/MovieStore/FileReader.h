// ---------------------- FileReader Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/28/2016
// ---------------------------------------------------------------------------
// Wrapper class for file reader.
//	Create file input object dynamicaly in memory
//	Reads in a file line by line
// ---------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class FileReader
{
public:
	FileReader();

	// Sets filename and creates a new object based on filename
	FileReader(const string &filename);

	//Frees up dynamicaly allocated memory
	~FileReader();

	// Reads the next line in the file
	//  Return true if successful, false otherwise
	//  Output result by reference
	bool getNextLine(string& result);

	// updates filename and deletes current *in object
	//	creates a new object based on new filename
	bool setFileName(const string &filename);
private:
	string filename;
	// Input file stream pointer to hold 
	//	the dynamic input file object.
	ifstream *in;
};
