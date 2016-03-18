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

bool ComedyMovie::operator==(const Movie &other) const
{
	return (name == other.getName() && releaseYear == other.getReleaseYear());
}

bool ComedyMovie::operator!=(const Movie &other) const
{
	return !operator==(other);
}

bool ComedyMovie::operator<(const Movie &other) const
{
	return (name < other.getName() || releaseYear < other.getReleaseYear());
}

bool ComedyMovie::operator<=(const Movie &other) const
{
	return (operator<(other) || operator==(other));
}

bool ComedyMovie::operator>(const Movie &other) const
{
	return (name > other.getName() || releaseYear > other.getReleaseYear());
}

bool ComedyMovie::operator>=(const Movie &other) const
{
	return (operator>(other) || operator==(other));
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