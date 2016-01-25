/**
 * @file	Thread.cpp
 *
 * @brief	Implements the thread class.
 */

#include "stdafx.h"
#include "Thread.h"
using namespace std;

Thread::Thread(unsigned int id) : m_id(id) {
	m_logger = spdlog::get("file_logger");
	m_logger->info("Creates thread_{}.", id);
};

Thread::~Thread() {
	for (auto&& message : m_messages) {
		delete message;
	}
	m_messages.clear();
	m_logger->info("Deleted thread_{}.", this->id());
}

const unsigned int Thread::id() {
	return m_id;
}

int Thread::add(Message* message) {
	m_logger->info("Try to add message_{} to thread_{}.", message->id(), this->id());
	if (message == nullptr){ // Check NUlL pointer;
		m_logger->info("Failed to add message_{} to thread_{}, check message.", message->id(), this->id());
		return EXIT_FAILURE;
	};
	// put the new messsage to the front of the queue.
	m_messages.push_front(message);
	m_logger->info("Successfully added message_{} to thread_{}.", message->id(), this->id());
	return EXIT_SUCCESS;
}

string Thread::str() {
	// Build the string representation as <thread_id>([message_id_1[, message_id_2...]])
	m_logger->info("Trying to get string representation of thread_{}.", this->id());
	string ret = "";
	for (const auto& message : m_messages) {
		ret = ret + (*message).str() + ", ";
	}
	ret = to_string(m_id) + "(" + (ret == "" ? ret : ret.substr(0, ret.size() - 2)) + ")";
	m_logger->info("Got string representation of thread_{} as: {}.", this->id(), ret);
	return ret;
}
