#include <iostream>

#ifndef __NODE_H
#define __NODE_H

using std::cout;
using std::endl;

template <class T>
class Node {
public:
	T info;
	Node *next, *prev;

	// constructor helps in updataing head, tail
	Node(const T& el, Node *n = 0, Node *p = 0) {
		info = el, next = n, prev = p;
	}
};

// interface
template <class T>
class DLinkList {
public:
	DLinkList() {
		head = tail = 0;
	}
	~DLinkList();
	int isEmpty() {
		return head == 0;
	}
	void addToHead(const T&);
	void addToTail(const T&);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(const T&);
	bool isInList(const T&) const;
	void traverseList(void);
protected:
	Node<T> *head, *tail;
};

template <class T>
DLinkList<T>::~DLinkList() {
	for (Node<T> *p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

template <class T>
void DLinkList<T>::addToHead(const T& el) {
	// new node becomes the head
	if (head != 0) {
		head = new Node<T>(el, head, 0);
		head->next->prev = head;
	} else {
		head = tail = new Node<T>(el);
	}
}

template <class T>
void DLinkList<T>::addToTail(const T& el) {
	if (tail != 0) {
		tail = new Node<T>(el, 0, tail);
		// new node becomes the tail
		tail->prev->next = tail;
	}
	else {
		head = tail = new Node<T>(el);
	}
}

template <class T>
T DLinkList<T>::deleteFromHead(void) {
	// XXX: empty list need to be handled in the application
	T el = head->info;
	if (head == tail) {
		delete head;
		head = tail = 0;
	} else {
		head = head->next;
		delete head->prev;
		head->prev = 0;
	}	

	return el;
}

template <class T>
T DLinkList<T>::deleteFromTail(void)
{
	// empty list need to be handled in the application
	T el = tail->info;
	if (tail == head) {
		delete head;
		tail = head = 0;
	} else {
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}

// node could be anywhere in the list or may not be even in the list
template <class T>
void DLinkList<T>::deleteNode(const T& el)
{
	// empty list need to be handled in the application

	// only one node and it matches the item being searched
	if (head == tail && head->info == el) {
		delete head;
		head = tail = 0;
	} else if (head->info == el) {
		Node<T> *tmp = head;
		head = head->next;
		delete tmp;
	} else {
		Node<T> *pred, *tmp;
		for (pred = head, tmp = head->next;
			tmp != 0 && !(tmp->info == el);
			pred = pred->next, tmp = tmp->next);

		if (tmp != 0) {
			pred->next = tmp->next;
			if (tmp->next != 0)
				tmp->next->prev = pred;
			if (tmp == tail)
				tail = pred;
			delete tmp;
		}
	}
}

template <class T>
bool DLinkList<T>::isInList(const T& el) const {
	Node<T> *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

	return tmp != 0;
}

template <class T>
void DLinkList<T>::traverseList(void)
{
	Node<T> *tmp;
	for (tmp = head; tmp != 0; tmp = tmp->next)
		cout << tmp->info << endl;
}

#endif // __NODE_H

