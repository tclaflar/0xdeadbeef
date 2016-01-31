#include "hash.h"
#include "string"

/**
  * @brief:  Class constructor
  * @param:  None
  * @retval: None
  */
hash::hash()
{
	size_t i;
	for (i = 0; i < m_tableSize; ++i) {
		m_hashTable[i] = new item;
		m_hashTable[i]->name = "";
		m_hashTable[i]->drink = "";
		m_hashTable[i]->next = NULL;
	}
}

/**
  * @brief:  Class destructor
  * @param:  None
  * @retval: None
  */
hash::~hash()
{
	size_t i;
	item *p = NULL;
	item *curr;
	for (i = 0; i < m_tableSize; ++i) {
		p = m_hashTable[i];
		if (p == NULL)
			continue;
		
		while (p->next != NULL) {
			curr = p;
			p = p->next;
			delete curr;
		}
	}

}

/**
  * @brief:  Add key-value pair in the hash-table 
  * @param:  name: key
  * @param:  drink: value
  * @retval: None
  */
void hash::AddItem(string name, string drink)
{
	int index = HashFn(name);
	if (m_hashTable[index]->name == "") {
		m_hashTable[index]->name = name;
		m_hashTable[index]->drink = drink;
	} else {
		item *curr = m_hashTable[index];
		item *p = new item;
		p->name = name;
		p->drink = drink;
		p->next = NULL;

		// insert the new node at the end
		while (curr->next != NULL) {
			curr = curr->next;;
		}

		curr->next = p;
	}
}

/**
  * @brief:  Find value associated with a key
  * @param:  name: key
  * @retval: drink: value associated with the key
  */
string hash::FindValue(string name)
{
	int index = HashFn(name);
	item *curr = m_hashTable[index];
	while (curr != NULL) {
		if (curr->name == name)
			return curr->drink;
		curr = curr->next;
	}

	return "";
		
}

/**
  * @brief:  Remove key 
  * @param:  name: key
  * @retval: None 
  */
void hash::RemoveItem(string name)
{
	int index = HashFn(name);
	
	item *p = m_hashTable[index];
	// nothing at this index
	if (!p)
		return;

	// only one node
	if ((p->name == name) && (p->next == NULL))
		delete p;

	// chain of node
	item *curr;

	while (p->next != NULL) {
		curr = p;
		p = p->next;
		if (p->name == name) {
			curr->next = p->next;
			delete p;
		}
	}

}

/**
  * @brief:  Trivial hash function 
  * @param:  key: string parameter as a key
  * @retval: bucket number in the hashtable
  */
size_t hash::HashFn(string key)
{
	size_t i, sum;
	sum = 0;
	for (i = 0; i < key.size(); ++i)
		sum += (int)key[i];

	return sum % m_tableSize;
}

