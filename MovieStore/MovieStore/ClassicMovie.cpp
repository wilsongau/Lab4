<<<<<<< HEAD
#include "ClassicMovie.h"

ClassicMovie::ClassicMovie()
{
	Movie('C', 0, "", "", 0, "D");
	starringActor = "";
	releaseMonth = 0;
}

ClassicMovie::ClassicMovie(int stock, const string & director, 
	const string &title, const string & star, int month, int year, 
	const string &type)
{
	Movie('C', stock, director, title, year, type);
	starringActor = star;
	releaseMonth = month;
}

ClassicMovie::~ClassicMovie()
{
}

string ClassicMovie::getStarringActor() const
{
	return starringActor;
}

int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}
=======
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
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
