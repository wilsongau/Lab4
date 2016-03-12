#include "ComedyMovie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ComedyMovie
// ----------------------------------------------------------------------------
ComedyMovie::ComedyMovie()
{
	Movie('D', 0, "", "", 0, ""); //empty ComedyMovie
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class ComedyMovie
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
ComedyMovie::ComedyMovie(int stock, const string & dir, const string & name,
	int year, const string & type)
{
	Movie('D', stock, dir, name, year, type);
}

<<<<<<< HEAD
=======
// ----------------------------------------------------------------------------
//	destructor
//  default  destructor for class ComedyMovie
// ----------------------------------------------------------------------------
>>>>>>> 1fb8973f3ef4cb0ffcf74c05761a87159f1ad391
ComedyMovie::~ComedyMovie()
{
}