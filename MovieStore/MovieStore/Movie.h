// ---------------------- Movie Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// inherits from: Item
// Header file for the Movie Class. Contains data and stock information
// for movies. Adds the director property.
// ---------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H


#include <string>
#include "Item.h"
using namespace std;

class Movie : public Item
{
	//overloads for printing or entering a movie 
	friend ostream& operator<<(ostream &out, const Movie &movie);
	friend istream& operator>>(istream &out, Movie &movie);

public:
	Movie();
	~Movie();

	//returns the director associated with a movie
	string getDirector() const;

	//returns the year the movie was released
	int getReleaseYear() const;

	//returns the type of the movie
	string getType() const;

	//returns the title of the movie
	virtual string getTitle() const;

protected:
	//the director of the movie
	string director;

	//the title of the movie
	string title;

	//the year the movie was released
	int releaseYear;

	//the type of movie such as DVD/VHS/BluRay
	string type;
};

#endif
