#include "ItemFactory.h"

// ----------------------------------------------------------------------------
//	MakeItem(string)
//  Create Item
// ----------------------------------------------------------------------------
Item * ItemFactory::MakeItem(string command, const string &identifier)
{
	Item *item = NULL;
	if (identifier == MOVIE_COMEDY)
	{
		ComedyMovie *temp = new ComedyMovie;
		if (temp->initialize(command))
		{
			return dynamic_cast<Item*>(temp);
		}
		delete temp;
	}
	else if (identifier == MOVIE_CLASSIC)
	{
		ClassicMovie *temp = new ClassicMovie;
		if (temp->initialize(command))
		{
			return dynamic_cast<Item*>(temp);
		}
		delete temp;
	}
	else if (identifier == MOVIE_DRAMA)
	{
		DramaMovie *temp = new DramaMovie;
		if (temp->initialize(command))
		{
			return dynamic_cast<Item*>(temp);
		}
		delete temp;
	}
	return item;
}
