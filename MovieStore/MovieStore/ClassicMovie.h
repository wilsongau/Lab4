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

#include "Movie.h"
class ClassicMovie :
	public Movie
{
	//overloads for printing or entering a Classic movie 
	friend ostream& operator<<(ostream &out, const ClassicMovie &movie);
	friend istream& operator>>(istream &out, ClassicMovie &movie);

public:
	ClassicMovie();
	ClassicMovie(const string &, const string &, const string &, int, int);
	~ClassicMovie();

	//returns the starring actor associated with this instance of a Classic movie
	string getStarringActor() const;

	//returns the month that the movie was released
	int getReleaseMonth() const;

private:
	//staring actor for this instance of a Classic movie
	string starringActor;

	//the month that the movie was released
	int releaseMonth;

	//used for when the data4movies file specifies what type of movie to store
	char identifier = 'C';
};
