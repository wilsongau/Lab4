// ---------------------- Movie Header --------------------------------------
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
#include <sstream>
using namespace std;

class Movie : public Item
{
	//overloads for printing or entering a movie 
	friend ostream& operator<<(ostream &out, const Movie &movie);

public:
	Movie();
	Movie(const Movie&);
	~Movie();

	Movie& operator=(const Movie &);
	//parse string for data to initialize the Movie with
	bool initialize(const string &cmd);

	//returns the director associated with a movie
	string getDirector() const;
	void setDirector(const string &dir);

	//returns the year the movie was released
	int getReleaseYear() const;
	void setReleaseYear(int year);

	//returns the type of the movie
	string getType() const;



protected:
	//the director of the movie
	string director;

	//the year the movie was released
	int releaseYear;

	//the type of movie such as DVD/VHS/BluRay
	string type;

	//process string to create proper object
	bool loadString(const string& info);
	bool is_number(const string& s) const;
};

#endif