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
	bool retrieve(const string &, T* &) const; //function to get the T* of a given object in the tree 
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
};

// ----------------------------------------------------------------------------
//	operator<<
//  overloaded output operator for class BinTree
// ----------------------------------------------------------------------------
template <typename T>
ostream &operator<<(ostream &sout, const BinTree<T> &tree)
{
	tree.display(tree.root, sout);
	sout << endl;
	return sout;
}

// ----------------------------------------------------------------------------
//	display
//  helper function to output operator for in order display
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::display(Node* pCurrentNode, ostream &sout) const
{
	if (pCurrentNode != NULL)  // traverse and print data
	{
		display(pCurrentNode->left, sout);
		sout << *pCurrentNode->data << " ";
		display(pCurrentNode->right, sout);
	}
}

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class BinTree
// ----------------------------------------------------------------------------
template <typename T>
BinTree<T>::BinTree()
{
	root = NULL;
}

// ----------------------------------------------------------------------------
//	constructor
//  copy constructor for class BinTree
// ----------------------------------------------------------------------------
template <typename T>
BinTree<T>::BinTree(const BinTree &other)
{
	root = NULL;
	*this = other;
}

// ----------------------------------------------------------------------------
//	destructor
//  destructor for class BinTree
// ----------------------------------------------------------------------------
template <typename T>
BinTree<T>::~BinTree()
{
	makeEmpty();
}

// ----------------------------------------------------------------------------
//	isEmpty
//  return true if BinTree is empty, false otherwise
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ----------------------------------------------------------------------------
//	makeEmpty
//  Remove the BinTree
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::makeEmpty()
{
	makeEmptyHelper(root);
}

// ----------------------------------------------------------------------------
//	makeEmptyHelper
//  Helper for makeEmpty, recursively remove the BinTree from specific Node
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::makeEmptyHelper(Node *&cur)
{
	if (cur != NULL)
	{
		makeEmptyHelper(cur->left);
		makeEmptyHelper(cur->right);

		delete cur->data;
		cur->data = NULL;
		cur->left = NULL;
		cur->right = NULL;
		delete cur;
		cur = NULL;
	}
}

// ----------------------------------------------------------------------------
//	operator=
//  Overload assignment operator
// ----------------------------------------------------------------------------
template <typename T>
BinTree<T> & BinTree<T>::operator=(const BinTree & other)
{
	if (this != &other)
	{
		if (!isEmpty())
		{
			makeEmpty();  // delete destination tree
		}
		if (!other.isEmpty())
		{
			copyTree(other.root, root);  // copy the tree
		}
	}
	return *this;
}

// ----------------------------------------------------------------------------
//	copyTree
//  Copy a tree in preorder traversal
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::copyTree(Node *source, Node *& target) const
{
	// preorder traversal
	if (source != NULL) // copy node
	{
		//Create new Node object for copy
		target = new Node;
		//Create new T* object for copy and use existing data
		T *temp = new T(*source->data);
		target->data = temp; //set data to be the same
							 //go left in BST
		copyTree(source->left, target->left);
		//go right in BST
		copyTree(source->right, target->right);
	}
	else
	{
		target = NULL;  // copy empty tree
	}
}

// ----------------------------------------------------------------------------
//	operator==
//  Overload equality operator
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::operator==(const BinTree & other) const
{
	if (root == NULL && other.root == NULL) //Both are empty BST
	{
		return true;
	}
	else
	{
		return isEqual(root, other.root); //Else compare recursively
	}
}

// ----------------------------------------------------------------------------
//	isEqual
//  Recursively compaing two tree from their stating node
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::isEqual(Node* original, Node* other) const
{
	if (original == NULL && other == NULL)
	{
		return true;
	}

	if (original == NULL || other == NULL)
	{
		return false;
	}

	if (*original->data == *other->data
		&& original->left == NULL && other->left == NULL
		&& original->right == NULL && other->right == NULL)
	{
		return true;
	}

	return (*original->data == *other->data
		&& isEqual(original->left, other->left)
		&& isEqual(original->right, other->right));
}

// ----------------------------------------------------------------------------
//	operator!=
//  overload inequality operator
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::operator!=(const BinTree &other) const
{
	return !(*this == other);
}


//bool BinTree<T>::insert(T* toInsert)
//{	
//	return insertHelper(root, toInsert);
//}
//
//// --------------------- insertHelper -----------------------------------------
//// Helper function to insert
//// If T is already in BSTree then node is not inserted
//// --------------------------------------------------------------
//bool BinTree<T>::insertHelper(Node*& current, T* toInsert)
//{
//	if (current == NULL)    // insert new node here
//	{
//		Node* newNode = new Node;	
//		current = newNode; // new nodes
//		current->data = toInsert;   // T set to node
//		toInsert = NULL;
//		current->left = NULL;   // left child set to NULL
//		current->right = NULL;  // right child set to NULL
//	}
//	else if (*toInsert < *current->data)
//	{
//		insertHelper(current->left, toInsert);  // traverse left
//	}
//	else if (*toInsert > *current->data)
//	{
//		insertHelper(current->right, toInsert); // traverse 
//	}
//	else
//	{
//		return false;   // node already exists and is not inserted
//	}
//
//	return true;    // node inserted
//}


// ----------------------------------------------------------------------------
//	insert
//  insert a T * to BinTree
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::insert(T* object)
{
	Node* newNode = new Node;
	newNode->data = object;
	object = NULL;
	newNode->left = newNode->right = NULL;
	if (isEmpty())
	{
		root = newNode; //Empty, object become root
	}
	else
	{
		Node* current = root;
		bool inserted = false;

		// if data is less than current data, insert in left subtree,
		// otherwise insert in right subtree
		while (!inserted)
		{
			if (*newNode->data == *current->data) //Duplicate found, remove newNode
			{
				delete newNode; //Handle duplicate properly
				newNode = NULL;
				return false;
			}
			else if (*newNode->data < *current->data)
			{
				if (current->left == NULL) // at leaf, insert left
				{
					current->left = newNode;
					inserted = true;
				}
				else
				{
					current = current->left;  //go further
				}
			}
			else
			{
				if (current->right == NULL) // at leaf, insert right
				{
					current->right = newNode;
					inserted = true;
				}
				else
				{
					current = current->right;  //go further
				}
			}
		}
	}
	return true;
}

// ----------------------------------------------------------------------------
//	retrieve
//  retrieve specific T within the tree
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::retrieve(const T &target, T *&result) const
{
	if (&target == NULL)
	{
		return false;
	}

	return retrieveHelper(root, target, result);
}


// ----------------------------------------------------------------------------
//	retrieve
//  retrieve specific T within the tree
// ----------------------------------------------------------------------------
template<typename T>
inline bool BinTree<T>::retrieve(const string &, T *&) const
{
	return false;
}

// ----------------------------------------------------------------------------
//	retrieveHelper
//  retrieve helper for retrieving T at specific location within BinTree
// ----------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::retrieveHelper(const Node *pCurrentNode, const T &target,
	T *&result) const
{
	if (pCurrentNode != NULL)
	{
		if (target == *pCurrentNode->data)
		{
			result = pCurrentNode->data;
			return true;
		}
		else if (target < *pCurrentNode->data)
		{
			return retrieveHelper(pCurrentNode->left, target, result);
		}
		else
		{
			return retrieveHelper(pCurrentNode->right, target, result);
		}
	}

	result = NULL;
	return false;
}


// ----------------------------------------------------------------------------
//	getHeight
//  returns the height of a given node within the BinTree
// ----------------------------------------------------------------------------
template <typename T>
int BinTree<T>::getHeight(const T &target) const
{
	return getHeightHelper(target, this->root);
}

// ----------------------------------------------------------------------------
//	getHeightHelper
//  Helper function to getHeight
// ----------------------------------------------------------------------------
template <typename T>
int BinTree<T>::getHeightHelper(const T &target, Node* current) const
{
	if (current == NULL)
	{
		return 0;   // node is not in tree, return height = 0
	}
	else if (*current->data == target)
	{
		return recursiveGetHeightHelper(current);   // node found
	}
	else
	{
		int left = getHeightHelper(target, current->left);  // search left
		int right = getHeightHelper(target, current->right);    // search right

		return max(left, right);
	}
}

// ----------------------------------------------------------------------------
//	recursiveGetHeightHelper
//  Recursively calculate the height of tree from specific Node
// ----------------------------------------------------------------------------
template <typename T>
int BinTree<T>::recursiveGetHeightHelper(Node* current) const
{
	if (current == NULL)
	{
		return 0;   // have reached a leaf node
	}
	else
	{
		// counts the amount of levels in the tree from root node
		return 1 + max(recursiveGetHeightHelper(current->left), recursiveGetHeightHelper(current->right));
	}
}

// ----------------------------------------------------------------------------
//	bstreeToArray
//  Move bst to array of T in order
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::bstreeToArray(T *result[])
{
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		//set to NULL
		delete result[i];
		result[i] = NULL;
	}
	/*static int tmp = 0;
	tmp++;
	cout << "bstreeToArrayHelper is called " << tmp << "times\n";*/
	bstreeToArrayHelper(root, result);
	makeEmpty(); //Make BST empty
}

// ----------------------------------------------------------------------------
//	bstreeToArrayHelper
//  Helper function to move bst to array of T in order from spcific 
//  location
// ----------------------------------------------------------------------------
template <typename T>
int BinTree<T>::bstreeToArrayHelper(Node* pCurrentNode, T *result[])
{
	if (pCurrentNode == NULL)
	{
		return 0;   // end of BST
	}

	int left = bstreeToArrayHelper(pCurrentNode->left, result);

	T *temp;
	temp = pCurrentNode->data; // saves T to temp
	pCurrentNode->data = NULL; // current no longer points to node
	*(result + left) = temp; //arrayToFill points to temp
	temp = NULL;

	int right = bstreeToArrayHelper(pCurrentNode->right, result + left + 1);

	return left + right + 1; // return position
}

// ----------------------------------------------------------------------------
//	arrayToBSTree
//  Build a balanced BST from array
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::arrayToBSTree(T *source[])
{
	makeEmpty(); //delete current tree

	int high = 0;

	for (int i = 0; i < 100; i++)    // assumed to be no more than 100 elements
	{
		if (source[i] != NULL)
		{
			high++; // find how many elements points to T
		}
		else
		{
			source[i] = NULL;
		}
	}
	arrayToBSTreeHelper(root, source, 0, high - 1);
}

// ----------------------------------------------------------------------------
//	arrayToBSTreeHelper
//  Helper function to build a balanced BST from array at specific location
// ----------------------------------------------------------------------------
template <typename T>
void BinTree<T>::arrayToBSTreeHelper(Node *current, T* source[], int low, int high)
{
	if (low > high)
	{
		current = NULL; // end of array T
	}
	else
	{
		int mid = (low + high) / 2; // picks T from array to build balanced tree

		T* temp; // temp T pointer
		temp = source[mid];    // assigns mid element from array section to temp
		source[mid] = NULL;    // sets that array element to NULL

		insert(temp);   // inserts T int BST
		arrayToBSTreeHelper(current, source, low, mid - 1);    // fill left
		arrayToBSTreeHelper(current, source, mid + 1, high);   // fill right
	}
}


#endif //BINTREE_H