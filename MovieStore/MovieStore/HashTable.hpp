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
#include "LinkedList.hpp"
#include <string>
using namespace std;

const int HASH_VALUE = 100;

template <class T>
class HashTable
{
public:
	HashTable(); //default constructor
	~HashTable(); //destructor

	bool get(const string &hashString, const T target, T &result) const; //Retrieving an element from the hash table
	bool Insert(T *item, const string &hashstring); //Insert element at the hash table
private:
	int hash(const string &hashString) const; //hash function to determine where to insert the data at hash table
	List342<T> *hashTable; //hash table
};

// ----------------------------------------------------------------------------
//	constructor
//  default constructor for class HashTable
// ----------------------------------------------------------------------------
template <class T>
HashTable<T>::HashTable()
{
	//initialize hashTable size to HASH_VALUE
	hashTable = new List342<T>[HASH_VALUE];
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
		hashTable[i].deleteList();
	}
	delete[] hashTable;
}

// ----------------------------------------------------------------------------
//	get
//  Retrieving an element from the hash table
// ----------------------------------------------------------------------------
template<class T>
bool HashTable<T>::get(const string & hashString, const T target, T & result) const
{
	//return retrieve function at LinkedList class at hashTable[hash(hashString)]
	int index = hash(hashString);
	return hashTable[index].Peek(target, result);
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
	hashTable[index].Insert(item);
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