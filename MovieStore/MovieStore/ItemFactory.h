// ---------------------- ItemFactory Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/26/2016
// ---------------------------------------------------------------------------
// Static class using the factory design pattern which will create Item objects
// depending on the criteria contained in the parameter's command string.
// ---------------------------------------------------------------------------

#include <string>
#include "Item.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
using namespace std;
static class ItemFactory
{
public:
	static Item*& MakeItem(string command, BinTree<Item> &inventory);
};
