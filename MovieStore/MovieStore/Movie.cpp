#include "Movie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Movie
// ----------------------------------------------------------------------------
Movie::Movie()
{
	Item('m', 0, "");
	director = "";
	releaseYear = 0;
	type = "";
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class Movie
// ----------------------------------------------------------------------------
Movie::Movie(char id, int stock, const string &dir, const string &name,
	int year, const string & type)
{
	Item(id, stock, name);
	director = dir;
	releaseYear = year;
	this->type = type;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Movie
// ----------------------------------------------------------------------------
Movie::~Movie()
{
}

// ----------------------------------------------------------------------------
//	getDirector()
//  return the directors of the movie
// ----------------------------------------------------------------------------
string Movie::getDirector() const
{
	return director;
}

// ----------------------------------------------------------------------------
//	getReleaseYear()
//  return the year the movie was released
// ----------------------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return releaseYear;
}

// ----------------------------------------------------------------------------
//	getType()
//  Return the movie type
// ----------------------------------------------------------------------------
string Movie::getType() const
{
	return type;
}


// ----------------------------------------------------------------------------
//	operator<<
//  output stream operator
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Movie &movie)
{
	out << movie.director << ", " << movie.name << ", " << movie.releaseYear;
	return out;
}

// ----------------------------------------------------------------------------
//	loadString(const string&)
//  load string to create proper object
// ----------------------------------------------------------------------------
void Movie::loadString(const string& info) 
{
	//info will look like: F, 10, Nora Ephron, Sleepless in Seattle, 1993
	//or: D, 10, Barry Levinson, Good Morning Vietnam, 1988
	stringstream ss;                 // string reader
	ss << info;                      // insert string info into reader
	string temp;                     //  temp string to parse the string
	getline(ss, temp, ',');          // get identifier
	identifier = temp[0];                  // assign identifier (char, so [0])
	getline(ss, temp, ',');          // get stock
	stringstream(temp) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, name, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> releaseYear;      // assign year
}