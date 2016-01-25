/**
 * @file	ThreadList.cpp
 *
 * @brief	Implements the ThreadList class.
 */

#include "stdafx.h"
#include <iostream>
#include "ThreadList.h"

using namespace std;

ThreadList::ThreadList(int k) : m_display_size(k) {
	// m_logger = spdlog::get("file_logger");
	// m_logger->info("Creates threalist with size: {}.", k);
}

ThreadList::~ThreadList() {
	for (auto&& thread : m_threads) {
		if (thread != nullptr) {
			delete thread;
		}
	}
	m_threads.clear();
	m_id_to_thread.clear();
	// m_logger->info("Deleted threadlist.");
}

int ThreadList::display_size() {
	return m_display_size;
}

int ThreadList::add(Message* message, unsigned int thread_id) {
	// m_logger->info("Try to add message_{} to threadlist.", message->id());
	if (message == nullptr || thread_id == NULL) {
		// m_logger->info("Failed to add message to threalist, check inputs: message = {}, thread_id = {}.", message->id(), thread_id);
		return EXIT_FAILURE;
	}
	// If the thread is in the threadlist, 
	// add the message to the message queue in the thread,
	// put the thread to the front of the threadlist.
	if (m_id_to_thread.find(thread_id) != m_id_to_thread.end()) {
		auto thread = m_id_to_thread[thread_id];
		int ret = (*thread)->add(message);
		if (ret == EXIT_FAILURE) {
			// m_logger->info("Failed to add message to threalist, check inputs: message = {}", message->id());
			return EXIT_FAILURE;
		}
		m_threads.splice(m_threads.begin(), m_threads, thread);
	} 
	// Else, create a new thread, add the message to it, 
	// and put it to the front of the list.
	// Also, add it to the id_to_thread map.
	else {
		Thread* thread = new Thread(thread_id);
		int ret = thread->add(message);
		if (ret == EXIT_FAILURE) {
			// m_logger->info("Failed to add message to threalist, check inputs: message = {}", message->id());
			return EXIT_FAILURE;
		}
		m_threads.push_front(thread);
		m_id_to_thread[thread_id] = m_threads.begin();
	}
	// m_logger->info("Added message_{} to thread_ {} in threadlist.", message->id(), thread_id);
	return EXIT_SUCCESS;
}

void ThreadList::display() {
	// Build the string representation of the threadlist as
	// [<thread_id>(message_id_1[, message_ids])[, <thread_id>(message_id_1[, message_ids])]]
	// m_logger->info("Try to display top {} threads in threadlist.", this->display_size());
	string print_out = "";
	int k = 0;
	for (const auto& thread : m_threads) {
		if (k++ == m_display_size) break;
		if (thread == nullptr) { // Check if thread somehow got deleted
			// m_logger->warn("thread in threadlist is null!");
			continue; // We don't return because showing something is better than showing nother in real life usage.
		}
		print_out = print_out + (*thread).str() + ", ";
	}
	print_out = "[" + (print_out == "" ? print_out : print_out.substr(0, print_out.size() - 2)) + "]";
	cout << print_out << endl;
	// m_logger->info("display top {} threads in threadlist as below:", this->display_size());
	// m_logger->info("{}", print_out);
}