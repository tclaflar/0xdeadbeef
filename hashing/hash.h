#include <iostream>
#include <string>
#include <stddef.h>
#include <cstdlib>
using namespace std;

#ifndef __HASH_H
#define __HASH_H

class hash {
private:
	static const int m_tableSize = 4;
	struct item {
		string name;
		string drink;
		item *next;
	};

	item *m_hashTable[m_tableSize];
public:
	// init hash table and allocate resource
	hash();

	// release resources
	~hash();

	// returns index number in the hash table
	size_t HashFn(string key);

	// add new item in the hash table
	void AddItem(string name, string drink);

	// return drink associated with the person
	string FindValue(string name);
	
	// remove key-value pair from the table
	void RemoveItem(string name);
};

#endif //__HASH_H

