#include "ClassicMovie.h"
// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::ClassicMovie()
{
	Movie('C', 0, "", "", 0, "D");
	starringActor = "";
	releaseMonth = 0;
}

ClassicMovie::ClassicMovie(const string & cmd, BinTree<Item> &inventory)
{
	//for classic: C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	stringstream ss;
	ss << cmd;
	string temp;                 // temp string to parse the string
	getline(ss, temp, ',');          // get identifier
	identifier = temp[0];                  // assign identifier (char, so [0])
	getline(ss, temp, ',');          // get stock
	stringstream(temp) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, name, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> releaseYear;      // assign year
	ss >> temp;                  // add first name of starring actor
	starringActor = temp;
	starringActor += ' ';
	ss >> temp;                 // add last name of starring actor
	starringActor += temp;
	ss >> releaseMonth;                // add month
	ss >> releaseYear;                 // add month
	findRelated(inventory);
}

// ----------------------------------------------------------------------------
//	constructor
//  overload constructor for class ClassicMovie
// ----------------------------------------------------------------------------
ClassicMovie::ClassicMovie(int stock, const string & director, 
	const string &title, const string & star, int month, int year, 
	const string &type, BinTree<Item> &inventory)
{
	Movie('C', stock, director, title, year, type);
	starringActor = star;
	releaseMonth = month;
	findRelated(inventory);

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

// ----------------------------------------------------------------------------
//	Borrow
//  Borrow's the ClassicMovie, if not in stock will check for other related 
//  movies that are in stock
// ----------------------------------------------------------------------------
bool ClassicMovie::Borrow(BorrowTransaction &t)
{
	if (stock > 0)
	{
		return true;
	}
	else
	{
		list<ClassicMovie*>::iterator iterator;
		for (iterator = related->begin(); iterator != related->end(); ++iterator)
		{
			if ((*iterator)->getStock() > 0)
			{
				string itemData = to_string((*iterator)->releaseMonth + (*iterator)->getReleaseYear()) + (*iterator)->starringActor;
				(*iterator)->stock--;
				t.setCheckedOut(true);
				t.setItemData(itemData);
				return true;
			}
		}
		return false;
	}
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


// ----------------------------------------------------------------------------
//	getStarringActor()
//  return the starringActor of the classic movie
// ----------------------------------------------------------------------------
string ClassicMovie::getStarringActor() const
{
	return starringActor;
}

// ----------------------------------------------------------------------------
//	getReleaseMonth
//  return the release month of the movie
// ----------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}
