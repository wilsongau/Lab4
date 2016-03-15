#include "FileReader.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class FileReader
// ----------------------------------------------------------------------------
FileReader::FileReader()
{
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class FileReader
// ----------------------------------------------------------------------------
FileReader::FileReader(const string & filename)
{
	ifstream infile1(filename);
	in = &infile1;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class FileReader
// ----------------------------------------------------------------------------

FileReader::~FileReader()
{
}

// ----------------------------------------------------------------------------
//	getNextLine(string &)
//  return true if it can get next line
// ----------------------------------------------------------------------------
bool FileReader::getNextLine(string & result)
{
	if ((*in).eof()) 
	{
		getline(*in, result);
		return true;
	}
	return false;
}

// ----------------------------------------------------------------------------
//	setFileName(const string &)
//  set the file name
// ----------------------------------------------------------------------------
bool FileReader::setFileName(const string & filename)
{
	ifstream newfile(filename);
	if (newfile)
	{
		in = &newfile;
		return true;
	}
	return false;
}