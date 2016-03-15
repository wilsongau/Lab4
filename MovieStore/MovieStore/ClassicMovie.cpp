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
