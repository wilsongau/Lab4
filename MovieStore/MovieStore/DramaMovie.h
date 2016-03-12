// ---------------------- DramaMovie Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// inherits from: Movie
// Header file for the DramaMovie Class.  Contains data and stock information
// for movies with the 'D' identifier. 
// ---------------------------------------------------------------------------

#include "Movie.h"
class DramaMovie :
	public Movie, public Item
{
	//overloads for printing or entering a Drama movie 
	friend ostream& operator<<(ostream &out, const DramaMovie &movie);
	friend istream& operator>>(istream &out, DramaMovie &movie);
public:
	DramaMovie();
	~DramaMovie();
	DramaMovie(int stock, const string &dir, const string &name,
		int year, const string & type);
};
