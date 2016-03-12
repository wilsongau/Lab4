#include "Movie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Movie
// ----------------------------------------------------------------------------
Movie::Movie()
{
	Item('m', 0, "");
	director = "";
	releaseYear = 0;
	type = "";
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class Movie
// ----------------------------------------------------------------------------
Movie::Movie(char id, int stock, const string &dir, const string &name,
	int year, const string & type)
{
	Item(id, stock, name);
	director = dir;
	releaseYear = year;
	this->type = type;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Movie
// ----------------------------------------------------------------------------
Movie::~Movie()
{
}

// ----------------------------------------------------------------------------
//	getDirector()
//  return the directors of the movie
// ----------------------------------------------------------------------------
string Movie::getDirector() const
{
	return director;
}

// ----------------------------------------------------------------------------
//	getReleaseYear()
//  return the year the movie was released
// ----------------------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return releaseYear;
}

// ----------------------------------------------------------------------------
//	getType()
//  Return the movie type
// ----------------------------------------------------------------------------
string Movie::getType() const
{
	return type;
}