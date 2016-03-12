#include "DramaMovie.h"

DramaMovie::DramaMovie()
{
	Movie('D', 0, "", "", 0, ""); //empty DramaMovie
}

DramaMovie::~DramaMovie()
{
}

DramaMovie::DramaMovie(int stock, const string & dir, const string & name, 
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}
