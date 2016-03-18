#include "ClassicMovie.h"
// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::ClassicMovie()
{
	Movie();
	starringActor = "";
	releaseMonth = 0;
	identifier = 'C';
}

// ----------------------------------------------------------------------------
//	destructor
//  default destructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
}

// ----------------------------------------------------------------------------
//	operator<<
//  output stream operator
// ----------------------------------------------------------------------------
ostream& operator<<(ostream &out, const ClassicMovie &movie)
{
	out << movie.director << ", " << movie.name << ", " << movie.starringActor 
		<< ", " << movie.releaseMonth << "/" << movie.releaseYear;
	return out;
}

// ----------------------------------------------------------------------------
//	findRelated
//  finds ClassicMovies in the store's inventory that have the same title, 
//  and release date
// ----------------------------------------------------------------------------
bool ClassicMovie::findRelated(BinTree<Item> & inventory)
{
	string itemData = to_string(releaseMonth + getReleaseYear()) + 
		starringActor;
	Item *item;
	inventory.retrieve(itemData, item);
	if (item == NULL)
	{
		return false;
	}
	((ClassicMovie*)&item)->addRelated(this);
	return true;
}


// prints all related ClassicMovies
void ClassicMovie::printAll() const
{
	list<ClassicMovie*>::iterator iterator;
	for (iterator = related->begin(); iterator != related->end(); ++iterator)
	{
		cout << *iterator;
	}
}

void ClassicMovie::addRelated(ClassicMovie * movie)
{
	if (related == NULL)
	{
		related = new list<ClassicMovie*>;
		related->push_back(this);
		related->push_back(movie);
		movie->related = related;
		return;
	}
	else
	{
		related->push_back(movie);
		movie->related = related;
	}
}

bool ClassicMovie::initialize(const string & cmd)
{
	//for classic: C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	stringstream ss;
	ss << cmd;
	string temp;                 // temp string to parse the string
	getline(ss, temp, ',');          // get identifier
	identifier = temp[0];                  // assign identifier (char, so [0])
	getline(ss, temp, ',');          // get stock
	if (!is_number(temp))
	{
		return false;
	}
	stringstream(temp) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, name, ',');         // assign title
	ss >> temp;                  // add first name of starring actor
	starringActor = temp;
	starringActor += ' ';
	ss >> temp;                 // add last name of starring actor
	starringActor += temp;
	ss >> temp;                // get month
	if (!is_number(temp))
	{
		return false;
	}
	stringstream(temp) >> releaseMonth;
	ss >> temp;                 // get year
	if (!is_number(temp))
	{
		return false;
	}
	stringstream(temp) >> releaseYear;
	return true;
}

bool ClassicMovie::initialize(const string & cmd, BinTree<Item>& inventory)
{
	//for classic: C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	stringstream ss;
	ss << cmd;
	string temp;                 // temp string to parse the string
	string numCheckTemp;

	getline(ss, temp, ',');          // get identifier
	//identifier = temp[0];                  // assign identifier (char, so [0])
	//if (identifier != 'C' || identifier != 'c')
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
	ss >> temp;                  // add first name of starring actor
	starringActor = temp;
	starringActor += ' ';
	ss >> temp;                 // add last name of starring actor
	starringActor += temp;
	ss >> temp;                // get month
	stringstream(temp) >> numCheckTemp;
	if (!is_number(numCheckTemp))
	{
		return false;
	}
	stringstream(temp) >> releaseMonth;
	ss >> temp;                 // get year
	stringstream(temp) >> numCheckTemp;
	if (!is_number(numCheckTemp))
	{
		return false;
	}
	stringstream(temp) >> releaseYear;
	findRelated(inventory);
	return true;
}

list<ClassicMovie*>& ClassicMovie::getRelated()
{
	return *related;
}


// ----------------------------------------------------------------------------
//	getStarringActor()
//  return the starringActor of the classic movie
// ----------------------------------------------------------------------------
string ClassicMovie::getStarringActor() const
{
	return starringActor;
}

void ClassicMovie::setStarringActor(const string & actor)
{
	starringActor = actor;
}

// ----------------------------------------------------------------------------
//	getReleaseMonth
//  return the release month of the movie
// ----------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}

void ClassicMovie::setReleaseMonth(int mon)
{
	releaseMonth = mon;
}

ClassicMovie & ClassicMovie::operator=(const ClassicMovie &other)
{
	stock = other.getStock();
	identifier = other.getIdentifier();
	releaseMonth = other.getReleaseMonth();
	releaseYear = other.getReleaseYear();
	director = other.getDirector();
	starringActor = other.getStarringActor();
	related = other.related;
	name = other.getName();
	return *this;
}

bool ClassicMovie::operator==(const ClassicMovie &other) const
{
	return (releaseMonth == other.getReleaseMonth() &&
		releaseYear == other.getReleaseYear() && 
		starringActor == other.getStarringActor());
}

bool ClassicMovie::operator!=(const ClassicMovie &other) const
{
	return !operator==(other);
}

bool ClassicMovie::operator<(const ClassicMovie &other) const
{
	return (releaseMonth < other.getReleaseMonth() ||
		releaseYear < other.getReleaseYear() ||
		starringActor < other.getStarringActor());
}

bool ClassicMovie::operator<=(const ClassicMovie &other) const
{
	return (operator<(other) || operator==(other));
}

bool ClassicMovie::operator>(const ClassicMovie &other) const
{
	return (releaseMonth > other.getReleaseMonth() ||
		releaseYear > other.getReleaseYear() ||
		starringActor > other.getStarringActor());
}

bool ClassicMovie::operator>=(const ClassicMovie &other) const
{
	return (operator>(other) || operator==(other));
}
