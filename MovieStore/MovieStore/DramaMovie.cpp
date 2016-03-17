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

bool DramaMovie::operator==(const Movie &other) const
{
	return (director == other.getDirector() && name == other.getName());

}

bool DramaMovie::operator!=(const Movie &other) const
{
	return !operator==(other);
}

bool DramaMovie::operator<(const Movie &other) const
{
	return (name < other.getName() || director < other.getDirector());
}

bool DramaMovie::operator<=(const Movie &other) const
{
	return (operator<(other) || operator==(other));
}

bool DramaMovie::operator>(const Movie &other) const
{
	return (name > other.getName() || director > other.getDirector());
}

bool DramaMovie::operator>=(const Movie &other) const
{
	return (operator<(other) || operator==(other));
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