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
