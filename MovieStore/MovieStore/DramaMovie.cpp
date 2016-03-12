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

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class DranaMovie
// ----------------------------------------------------------------------------
DramaMovie::DramaMovie(int stock, const string & dir, const string & name, 
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}
