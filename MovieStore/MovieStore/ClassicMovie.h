// ---------------------- ClassicMovie Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// inherits from: Movie
// Header file for the ClassicMovie Class.  Contains data and stock information
// for movies with the 'C' identifier. Adds releaseMonth and starringActor
// properties.
// ---------------------------------------------------------------------------
#ifndef CLASSIC_MOVIE_HEADER
#define CLASSIC_MOVIE_HEADER
#include "Movie.h"
#include "bintree.hpp"
#include <list>
using namespace std;
class ClassicMovie :
	public Movie
{
	//overloads for printing or entering a Classic movie 
	friend ostream& operator<<(ostream &out, const ClassicMovie &movie);

public:
	ClassicMovie();
	~ClassicMovie();

	//returns the starring actor associated with this instance of a Classic movie
	string getStarringActor() const;
	void setStarringActor(const string &actor);

	//returns the month that the movie was released
	int getReleaseMonth() const;
	void setReleaseMonth(int mon);

	ClassicMovie& operator=(const ClassicMovie &);
	bool operator==(const ClassicMovie &) const;
	bool operator!=(const ClassicMovie &) const;
	bool operator<(const ClassicMovie &) const;
	bool operator<=(const ClassicMovie &) const;
	bool operator>(const ClassicMovie &) const;
	bool operator>=(const ClassicMovie &) const;
	
	// finds a related ClassicMovie with the listed starring actor
	bool findRelated(BinTree<Item> & inventory);
	void addRelated(ClassicMovie * movie);
	bool initialize(const string &cmd);
	bool initialize(const string &cmd, BinTree<Item> &inventory);
	list<ClassicMovie*>& getRelated();
	void printAll() const;
private:
	//staring actor for this instance of a Classic movie
	string starringActor;

	//the month that the movie was released
	int releaseMonth;

	// list of related ClassicMovies
	list<ClassicMovie*> * related = NULL;

};
#endif