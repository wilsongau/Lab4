#include "FileReader.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class FileReader
// ----------------------------------------------------------------------------
FileReader::FileReader()
{
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class FileReader
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
FileReader::FileReader(const string & filename)
{
	ifstream infile1(filename);
	in = &infile1;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class FileReader
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
FileReader::~FileReader()
{
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	getNextLine(string &)
//  return true if it can get next line
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
bool FileReader::getNextLine(string & result)
{
	if ((*in).eof()) 
	{
		getline(*in, result);
		return true;
	}
	return false;
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	setFileName(const string &)
//  set the file name
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
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