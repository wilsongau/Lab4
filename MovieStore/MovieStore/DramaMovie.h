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
#ifndef DRAMA_HEADER
#define DRAMA_HEADER
#include "Movie.h"
class DramaMovie :
	public Movie
{
	//overloads for printing or entering a Drama movie 
	friend ostream& operator<<(ostream &out, const DramaMovie &movie);
public:
	DramaMovie();
	~DramaMovie();
};
#endif