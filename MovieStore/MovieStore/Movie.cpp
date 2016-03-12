#include "Movie.h"

Movie::Movie()
{
	Item('m', 0, "");
	director = "";
	releaseYear = 0;
	type = "";
}

Movie::Movie(char id, int stock, const string &dir, const string &name,
	int year, const string & type)
{
	Item(id, stock, name);
	director = dir;
	releaseYear = year;
	this->type = type;
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
