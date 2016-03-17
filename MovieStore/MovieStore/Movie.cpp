#include "Movie.h"

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class Movie
// ----------------------------------------------------------------------------
Movie::Movie()
{
	Item();
	director = "";
	releaseYear = 0;
	type = "";
}

Movie::Movie(const Movie &other)
{
	*this = other;
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class Movie
// ----------------------------------------------------------------------------
Movie::~Movie()
{
}

Movie & Movie::operator=(const Movie &other)
{
	stock = other.getStock();
	identifier = other.getIdentifier();
	releaseYear = other.getReleaseYear();
	director = other.getDirector();
	name = other.getName();
	return *this;
}

bool Movie::initialize(const string & cmd)
{
	return loadString(cmd);
}

// ----------------------------------------------------------------------------
//	getDirector()
//  return the directors of the movie
// ----------------------------------------------------------------------------
string Movie::getDirector() const
{
	return director;
}

void Movie::setDirector(const string & dir)
{
	director = dir;
}

// ----------------------------------------------------------------------------
//	getReleaseYear()
//  return the year the movie was released
// ----------------------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return releaseYear;
}

void Movie::setReleaseYear(int year)
{
	releaseYear = year;
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
bool Movie::loadString(const string& info)
{
	//info will look like: F, 10, Nora Ephron, Sleepless in Seattle, 1993
	//or: D, 10, Barry Levinson, Good Morning Vietnam, 1988
	std::stringstream ss;                 // string reader
	ss << info;                      // insert string info into reader
	string temp;                     //  temp string to parse the string
	string numCheckTemp;
	getline(ss, temp, ',');          // get identifier
	identifier = temp[0];                  // assign identifier (char, so [0])
										   //if (identifier != 'F' || identifier != 'f' || identifier != 'D' || identifier != 'd')
										   //{
										   //	return false;
										   //}
	getline(ss, temp, ',');          // get stock
	stringstream(temp) >> numCheckTemp;
	if (!is_number(numCheckTemp))
	{
		return false;
	}
	stringstream(temp) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, name, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> numCheckTemp;
	if (!is_number(numCheckTemp))
	{
		return false;
	}
	stringstream(temp) >> releaseYear;      // assign year
	return true;
}

bool Movie::is_number(const string & s) const
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	{
		++it;
	}
	return (!s.empty() && it == s.end());
}