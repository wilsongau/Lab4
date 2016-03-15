// ---------------------- HashTable<T> Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// Templatized HashTable class. Calculates the hashcode based off a string
// that is passed in along with a pointer to the object that is to be stored.
// Uses the closed hashing format of hashtables.
// ---------------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
//#include "LinkedList.hpp"
#include <string>
#include <list>
using namespace std;

const int HASH_VALUE = 100;

template <class T>
class HashTable
{
public:
	HashTable(); //default constructor
	~HashTable(); //destructor

	//Retrieves an element from the hash table
	bool get(const string &hashString, const T target, T &result) const; 

	//Insert element at the hash table
	bool Insert(T *item, const string &hashstring); 
private:
	//hash function to determine where to insert the data at hash table
	int hash(const string &hashString) const;
	list<T> *hashTable; //hash table
};

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class HashTable
// ----------------------------------------------------------------------------
template <class T>
HashTable<T>::HashTable()
{
	hashTable = new list<T>[HASH_VALUE];
}

// ----------------------------------------------------------------------------
//	destructor
//  destructor for class HashTable
// ----------------------------------------------------------------------------
template <class T>
HashTable<T>::~HashTable()
{
	for (int i = 0; i < HASH_VALUE; i++)
	{
		hashTable[i].clear();
	}
}

// ----------------------------------------------------------------------------
//	get
//  Retrieving an element from the hash table
// ----------------------------------------------------------------------------
template<class T>
bool HashTable<T>::get(const string & hashString, const T target, T & result) const //why do we have target and result? would they be the same?
{
	//return retrieve function at LinkedList class at hashTable[hash(hashString)]
	int index = hash(hashString);
	return hashTable[index].Peek(target, result); //WE DON'T HAVE PEEK ANYMORE, since you use STD library list
	//I am not sure if this is the correct way to do this
	list<T>::iterator iter = find(hashTable[index].begin(), hashTable[index], target);
	if (iter == target)
	{
		result = target;
		return true;
	}
	return false;
}

// ----------------------------------------------------------------------------
//	Insert
//  Insert an element at HashTable
// ----------------------------------------------------------------------------
template<class T>
bool HashTable<T>::Insert(T * item, const string & hashstring)
{
	//call insert function from LinkedList class at hashTable[hash(hashString)]
	int index = hash(hashstring);
	//hashTable[index].Insert(item);    //since we use STD library, shouldn't we use push_back from list??
	hashTable[index].push_back(item);
}

// ----------------------------------------------------------------------------
//	hash
//  hash function to determine where to insert the data at hash table
// ----------------------------------------------------------------------------
template<class T>
int HashTable<T>::hash(const string & hashString) const
{
	//return the ASCII value of the hashString, then mod it with HASH_VALUE
	int value = 0;
	for (int i = 0; i < hashString.length(); i++)
		value += hashString[i];
	return (value * hashString.length()) % length;
}

#endif
