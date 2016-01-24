/**
 * @file	ThreadList.cpp
 *
 * @brief	Implements the ThreadList class.
 */

#include "stdafx.h"
#include <iostream>
#include "ThreadList.h"

using namespace std;

ThreadList::ThreadList(int k) : m_display_size(k) {};

void ThreadList::add(Message* message, unsigned int thread_id) {
	// If the thread is in the threadlist, 
	// add the message to the message queue in the thread,
	// put the thread to the front of the threadlist.
	if (m_id_to_thread.find(thread_id) != m_id_to_thread.end()) {
		auto thread = m_id_to_thread[thread_id];
		m_threads.splice(m_threads.begin(), m_threads, thread);
		(*thread)->add(message);
	} 
	// Else, create a new thread, add the message to it, 
	// and put it to the front of the list.
	// Also, add it to the id_to_thread map.
	else {
		Thread* thread = new Thread(thread_id);
		thread->add(message);
		m_threads.push_front(thread);
		m_id_to_thread[thread_id] = m_threads.begin();
	}
}

void ThreadList::display() {
	// Build the string representation of the threadlist as
	// [<thread_id>(message_id_1[, message_ids])[, <thread_id>(message_id_1[, message_ids])]]
	string print_out = "";
	int k = 0;
	for (const auto& thread : m_threads) {
		if (k++ == m_display_size) break;
		print_out = print_out + (*thread).str() + ", ";
	}
	print_out = "[" + (print_out == "" ? print_out : print_out.substr(0, print_out.size() - 2)) + "]";
	cout << print_out << endl;
}