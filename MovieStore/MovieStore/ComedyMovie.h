// ---------------------- ClassicMovie Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// inherits from: Movie
// Header file for the ClassicMovie Class.  Contains data and stock information
// for movies with the 'F' identifier. 
// ---------------------------------------------------------------------------

#include "Movie.h"
class ComedyMovie :
	public Movie, public Item
{
	//overloads for printing or entering a Comedy movie 
	friend ostream& operator<<(ostream &out, const ComedyMovie &movie);
	friend istream& operator>>(istream &out, ComedyMovie &movie);
public:
	ComedyMovie();
	ComedyMovie(const string &cmd);
	ComedyMovie(int stock, const string &dir, const string &name,
		int year, const string & type);
	~ComedyMovie();
};
