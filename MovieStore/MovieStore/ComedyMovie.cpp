#include "ComedyMovie.h"

ComedyMovie::ComedyMovie()
{
	Movie('D', 0, "", "", 0, ""); //empty ComedyMovie
}

ComedyMovie::ComedyMovie(int stock, const string & dir, const string & name,
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}

ComedyMovie::~ComedyMovie()
{
}