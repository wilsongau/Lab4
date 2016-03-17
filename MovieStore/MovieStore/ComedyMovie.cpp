#include "ComedyMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::ComedyMovie()
{
	Movie(); //empty ComedyMovie
}

ComedyMovie::ComedyMovie(const string & cmd)
{
	loadString(cmd);
}

// ----------------------------------------------------------------------------
//	destructor
//  default  destructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::~ComedyMovie()
{
}


// ----------------------------------------------------------------------------
//	operator<<
//  output stream operator
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const ComedyMovie &movie)
{
	out << movie.director << ", " << movie.name << ", " << movie.releaseYear;
	return out;
}