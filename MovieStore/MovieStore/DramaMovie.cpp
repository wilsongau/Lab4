#include "DramaMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class DramaMovie
// ----------------------------------------------------------------------------
DramaMovie::DramaMovie()
{
	Movie('D', 0, "", "", 0, ""); //empty DramaMovie
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class DramaMovie
// ----------------------------------------------------------------------------
DramaMovie::~DramaMovie()
{
}

DramaMovie::DramaMovie(const string & cmd)
{
	loadString(cmd);
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class DranaMovie
// ----------------------------------------------------------------------------
DramaMovie::DramaMovie(int stock, const string & dir, const string & name, 
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}


// ----------------------------------------------------------------------------
//	operator<<
//  output stream operator
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const DramaMovie &movie)
{
	out << movie.director << ", " << movie.name << ", " << movie.releaseYear;
	return out;
}