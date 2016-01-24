/**
 * @file	ThreadedMessenger.cpp
 *
 * @brief	This is the entry point of the program, 
 * 			it mainly shows some example of displaying 
 * 			the state of the threalist.
 */

#include "stdafx.h"
#include <iostream>
#include "ThreadList.h"

using namespace std;

int _tmain()
{
	// Create new threadlist that shows only the top 3 threads. state: [].
	cout << "Create new threadlist that shows only the top 3 threads." << endl;
	ThreadList* threadlist = new ThreadList(3);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	// Add (M13, T7), state: [7(13)].
	cout << "Add (M13, T7)" << endl;
	Message* message_13 = new Message(13, "Head of Message 13", "Content of Message 13");
	threadlist->add(message_13, 7);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	// Add (M5, T99), state: [99(5), 7(13)].
	cout << "Add (M5, T99)" << endl;
	Message* message_5 = new Message(5, "Head of Message 5", "Content of Message 5");
	threadlist->add(message_5, 99);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	// Add (M4, T11), state: [11(4), 99(5), 7(13)].
	cout << "Add (M4, T11)" << endl;
	Message* message_4 = new Message(4, "Head of Message 4", "Content of Message 4");
	threadlist->add(message_4, 11);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	// Add (M1, T1), state: [1(1), 11(4), 99(5), 7(13)] => [1(1), 11(4), 99(5)].
	cout << "Add (M4, T11)" << endl;
	Message* message_1 = new Message(1, "Head of Message 1", "Content of Message1");
	threadlist->add(message_1, 1);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	// Add (M2, T7), state: [7(2, 13), 1(1), 11(4), 99(5)] => [7(2, 13), 1(1), 11(4)].
	cout << "Add (M2, T7)" << endl;
	Message* message_2 = new Message(2, "Head of Message 2", "Content of Message2");
	threadlist->add(message_2, 7);
	cout << "State: ";
	threadlist->display();
	cout << endl;

	cin.ignore();
	return 0;
}

