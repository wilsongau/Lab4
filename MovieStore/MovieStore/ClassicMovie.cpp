#include "ClassicMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::ClassicMovie()
{
	Movie('C', 0, "", "", 0, "D");
	starringActor = "";
	releaseMonth = 0;
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::ClassicMovie(int stock, const string & director, 
	const string &title, const string & star, int month, int year, 
	const string &type)
{
	Movie('C', stock, director, title, year, type);
	starringActor = star;
	releaseMonth = month;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
}

// ----------------------------------------------------------------------------
//	getStarringActor()
//  return the starringActor of the classic movie
// ----------------------------------------------------------------------------
string ClassicMovie::getStarringActor() const
{
	return starringActor;
}

// ----------------------------------------------------------------------------
//	getReleaseMonth
//  return the release month of the movie
// ----------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}
