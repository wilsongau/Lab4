#include "ItemFactory.h"

// ----------------------------------------------------------------------------
//	MakeItem(string)
//  Create Item
// ----------------------------------------------------------------------------
Item *& ItemFactory::MakeItem(string command, BinTree<Item> &inventory)
{
	Item *item = NULL;
	if (command == MOVIE_COMEDY)
	{
		item = (Item*)new ComedyMovie(command);
	}
	else if (command == MOVIE_CLASSIC)
	{
		item = (Item*)new ClassicMovie(command, inventory);
	}
	else if (command == MOVIE_DRAMA)
	{
		item = (Item*)new DramaMovie(command);
	}
	else
	{
		cerr << "Invalid Item Creation Command: " << command << endl;
	}
	return item;
}
