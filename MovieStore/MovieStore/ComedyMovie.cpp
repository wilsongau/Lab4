#include "ComedyMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::ComedyMovie()
{
	Movie('D', 0, "", "", 0, ""); //empty ComedyMovie
}
ComedyMovie::ComedyMovie(const string & cmd)
{
}
// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::ComedyMovie(int stock, const string & dir, const string & name,
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}

// ----------------------------------------------------------------------------
//	destructor
//  default  destructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::~ComedyMovie()
{
}