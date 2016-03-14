#include "ItemFactory.h"

// ----------------------------------------------------------------------------
//	MakeItem(string)
//  Create Item
// ----------------------------------------------------------------------------
Item *& ItemFactory::MakeItem(string command, BinTree<Item> &inventory)
{
	const static string MOVIE_COMEDY = "F";
	const static string MOVIE_CLASSIC = "C";
	const static string MOVIE_DRAMA = "D";
	Item *item = NULL;
	if (command == MOVIE_COMEDY)
	{
		item = new ComedyMovie(command);
	}
	else if (command == MOVIE_CLASSIC)
	{
		item = new ClassicMovie(command, inventory);
	}
	else if (command == MOVIE_DRAMA)
	{
		item = new DramaMovie(command);
	}
	else
	{
		cerr << "Invalid Item Creation Command: " << command << endl;
	}
	return item;
}
