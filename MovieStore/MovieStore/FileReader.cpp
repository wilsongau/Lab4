#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::FileReader(const string & filename)
{
	ifstream infile1(filename);
	in = &infile1;
}

FileReader::~FileReader()
{
}

bool FileReader::getNextLine(string & result)
{
	if ((*in).eof()) 
	{
		getline(*in, result);
		return true;
	}
	return false;
}

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