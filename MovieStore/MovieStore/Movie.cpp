#include "Movie.h"

Movie::Movie()
{
}

Movie::~Movie()
{
}

string Movie::getDirector() const
{
	return director;
}

int Movie::getReleaseYear() const
{
	return releaseYear;
}

string Movie::getType() const
{
	return type;
}

string Movie::getTitle() const
{
	return title;
}
