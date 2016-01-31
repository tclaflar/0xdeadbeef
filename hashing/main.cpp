#include <iostream>
#include "hash.h"

/**
  * @brief:  Test hashing with chaining 
  * @param:  None
  * @note:   TODO: Pass or Fail report
  * @retval: None
  */
void testHashFn(void)
{
	hash h1;

	cout << "----------------------------------------------" << endl;
	h1.AddItem("Panda", "Bamboo shot");
	h1.AddItem("adnap", "Mojito"); // index to same bucket as Panda
	h1.AddItem("panad", "Coffee"); // index to same bucket as Panda
	h1.AddItem("Goblin", "Toadflax"); 
	h1.AddItem("Witch", "Goat's blood");
	cout << "----------------------------------------------" << endl;
	cout << "Panda drinks: " << h1.FindValue("Panda") << endl;
	cout << "adnap drinks: " << h1.FindValue("adnap") << endl;
	cout << "panad drinks: " << h1.FindValue("panad") << endl;
	// negative test
	cout << "nobody drinks: " << h1.FindValue("nobody") << endl;
	cout << "Goblin drinks: " << h1.FindValue("Goblin") << endl;
	cout << "Witch drinks: " << h1.FindValue("Witch") << endl;
	cout << "----------------------------------------------" << endl;
	cout << "After removing adnap, panad and Panda from table" << endl;
	cout << "----------------------------------------------" << endl;
	h1.RemoveItem("Panda");	
	h1.RemoveItem("adnap");	
	h1.RemoveItem("panad");	
	h1.RemoveItem("Panda");	
	cout << "----------------------------------------------" << endl;
	cout << "Panda drinks: " << h1.FindValue("Panda") << endl;
	cout << "adnap drinks: " << h1.FindValue("adnap") << endl;
	cout << "panad drinks: " << h1.FindValue("panad") << endl;
	cout << "nobody drinks: " << h1.FindValue("nobody") << endl;
	cout << "Goblin drinks: " << h1.FindValue("Goblin") << endl;
	cout << "Witch drinks: " << h1.FindValue("Witch") << endl;
	cout << "----------------------------------------------" << endl;
}

/**
  * @brief:  Entry function 
  * @param:  None
  * @retval: 0
  */
int main(void)
{
	testHashFn();
	return 0;
}
