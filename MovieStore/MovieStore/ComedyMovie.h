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
#ifndef COMEDY_MOVIE_HEADER
#define COMEDY_MOVIE_HEADER
#include "Movie.h"
using namespace std;
class ComedyMovie :
	public Movie
{
	//overloads for printing or entering a Comedy movie 
	friend ostream& operator<<(ostream &out, const ComedyMovie &movie);
public:
	ComedyMovie();
	ComedyMovie(const string &cmd);
	~ComedyMovie();
	bool operator==(const Movie &) const;
	bool operator!=(const Movie &) const;
	bool operator<(const Movie &) const;
	bool operator<=(const Movie &) const;
	bool operator>(const Movie &) const;
	bool operator>=(const Movie &) const;

};
#endif