#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

void testDLgrades(void);

int main(void)
{
	testDLgrades();
	return 0;
}

void testDLgrades(void)
{
	cout <<"----------0xdeadbeef----------------"<< endl;
	int val;
	DLinkList<double> grades;
	grades.addToHead(4.2);
	grades.addToHead(5);
	grades.addToTail(1.5);
	grades.addToTail(2);
	grades.addToTail(3.4);
	grades.addToTail(4.1);
	grades.addToTail(4.9);

	// delete 5 
	if (!grades.isEmpty())
		val = grades.deleteFromHead();
	else 
		cout << "grades is empty" << endl;
	
	// expect 5
	cout << "value deleted: " << val << endl;
	

	if (!grades.isEmpty())
		grades.deleteNode(3.4);
	
	// negative test
	if (!grades.isEmpty())
		grades.deleteNode(34);

	// expect 4.2 1.5 2 3.4 4.1 4.9
	grades.traverseList();

	// expect true
	if (grades.isInList(4.9))
		cout << "found" << endl;

	cout <<"----------0xdeadbeef----------------"<< endl;
}
