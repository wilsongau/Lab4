#include "ItemFactory.h"

// ----------------------------------------------------------------------------
//	MakeItem(string)
//  Create Item
// ----------------------------------------------------------------------------
Item * ItemFactory::MakeItem(string command, const string &identifier, 
	BinTree<Item> &inventory)
{
	Item *item = NULL;
	if (identifier == MOVIE_COMEDY)
	{
		item = (Item*)new ComedyMovie(command);
	}
	else if (identifier == MOVIE_CLASSIC)
	{
		item = (Item*)new ClassicMovie(command, inventory);
	}
	else if (identifier == MOVIE_DRAMA)
	{
		item = (Item*)new DramaMovie(command);
	}
	else
	{
		cerr << "Invalid Item Creation Command: " << command << endl;
	}
	return item;
}
