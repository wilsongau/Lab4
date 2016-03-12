#include "ClassicMovie.h"

ClassicMovie::ClassicMovie()
{
}

ClassicMovie::ClassicMovie(const string & directorIn, const string & titleIn, const string & starIn, int monthIn, int yearIn)
{
	director = directorIn;
	title = titleIn;
	starringActor = starIn;
	releaseMonth = monthIn;
	releaseYear = yearIn;
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
