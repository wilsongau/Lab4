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
		item = (Item*)new ComedyMovie;
		if (!item->initialize(command))
		{
			delete item;
			item = NULL;
		}
	}
	else if (identifier == MOVIE_CLASSIC)
	{
		ClassicMovie *temp = new ClassicMovie;
		if (!temp->initialize(command, inventory))
		{
			delete item;
			item = NULL;
		}
		item = (Item*)temp;
	}
	else if (identifier == MOVIE_DRAMA)
	{
		item = (Item*)new DramaMovie;
		if (!item->initialize(command))
		{
			delete item;
			item = NULL;
		}
	}
	return item;
}
