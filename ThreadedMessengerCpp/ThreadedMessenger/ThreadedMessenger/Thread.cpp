/**
 * @file	Thread.cpp
 *
 * @brief	Implements the thread class.
 */

#include "stdafx.h"
#include "Thread.h"
using namespace std;

Thread::Thread(unsigned int id) : m_id(id) {};

const unsigned int Thread::id() {
	return m_id;
}

void Thread::add(Message* message) {
	// put the new messsage to the front of the queue.
	m_messages.push_front(message);
}

string Thread::str() {
	// Build the string representation as <thread_id>([message_id_1[, message_id_2...]])
	string ret = "";
	for (const auto& message : m_messages) {
		ret = ret + (*message).str() + ", ";
	}
	ret = to_string(m_id) + "(" + (ret == "" ? ret : ret.substr(0, ret.size() - 2)) + ")";
	return ret;
}
