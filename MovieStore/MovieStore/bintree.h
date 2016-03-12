//----------------------------------------------------------------------------
//    File:		bintree.h
//
//    Class:	BinTree
//----------------------------------------------------------------------------


#pragma once
#ifndef BINTREE_H
#define BINTREE_H
#include <algorithm> 
using namespace std;
const int MAX_ARRAY_SIZE = 100;
//----------------------------------------------------------------------------
//
//    Title:		BinTree Class
//
//    Description:	This class create a BST object, which allow for tree 
//					building, tree modifing, and tree destroying. Also,
//					functions to build array of T* from the BST or 
//					turn BST into an array of T* are provided
//
//    Programmer:	Wilson Gautama
//   
//    Date:			1/30/2016
// 
//    Version:		1.00
//  
//    Environment:
//       Hardware: Intel i5 PC
//       Software: Windows 10.1
//       Compiles under Microsoft Visual Studio 2015 and UWB Linux Lab using Putty
//
//
//    History Log:
//		1/22/16	WG  started version 1.00
//		1/30/16 WG finished version 1.00
//
// ----------------------------------------------------------------------------
// Assumptions: All input is assumed to be correct and all of the
// BSTs are assumed to be 100 nodes or less. T class assumed to be
// included by user.
//-----------------------------------------------------------------------------
template <typename T>
class BinTree 
{
	//operator<< overload
	friend ostream& operator<<(ostream&, const BinTree&);

public:
	//constructor and destructor
	BinTree(); //default constructor
	BinTree(const BinTree&); //copy constructor
	~BinTree(); //destructor

	//Functions used to modify BST
	bool insert(T*); //function to insert T* to tree
	bool retrieve(const T &, T* &) const; //function to get the T* of a given object in the tree 
	int getHeight(const T &) const; // function to find the height of a given value in the tree
	bool isEmpty() const; // true if tree is empty, otherwise false
	void makeEmpty(); // make the tree empty   
	void bstreeToArray(T*[]); //function to fill an array of T* by using an inorder traversal of the tree. After the function, it leaves the tree empty.
	void arrayToBSTree(T*[]); //function to build a balanced BinTree from a sorted array of T*. After the function, array will be filled with NULLs.

	//Overloaded operators
	BinTree<T>& operator=(const BinTree&);
	bool operator==(const BinTree&) const;
	bool operator!=(const BinTree&) const;

private:
	//Struct holds pointers to data and left/right ancestors
	struct Node
	{
		T* data; //Pointer to data contained in T
		Node *left; //Left child pointer
		Node *right; //Right child pointer
	};

	Node *root; // root of the tree

	// helper functions
	void display(Node*, ostream &) const; //Displays BST inorder
	bool retrieveHelper(const Node *, const T &, T *&) const; //Retrieve helper
	void makeEmptyHelper(Node *&); //Delete all tree from the given Node
	int getHeightHelper(const T &, Node*) const; //Helper function for getHeight
	int recursiveGetHeightHelper(Node*) const; //recursive getHeight helper
	bool isEqual(Node*, Node*) const; //Checks if two nodes equal
	int bstreeToArrayHelper(Node*, T*[]); //bstToArray helper
	void arrayToBSTreeHelper(Node *, T*[], int, int); //helper for arraytoBST
	void copyTree(Node*, Node*&) const; //Make a copy of BST

	bool insertHelper(Node*&, T*);
};

#endif //BINTREE_H