#include "DramaMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class DramaMovie
// ----------------------------------------------------------------------------
DramaMovie::DramaMovie()
{
	Movie(); //empty DramaMovie
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class DramaMovie
// ----------------------------------------------------------------------------
DramaMovie::~DramaMovie()
{
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