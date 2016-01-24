#include "stdafx.h"
#include <iostream>
#include "ThreadList.h"

using namespace std;

ThreadList::ThreadList(int k) : m_display_size(k) {};

void ThreadList::add(Message* message, unsigned int thread_id) {
	// auto found_thread = m_id_to_thread.find(thread_id);
	if (m_id_to_thread.find(thread_id) != m_id_to_thread.end()) {
		auto thread = m_id_to_thread[thread_id];
		m_threads.splice(m_threads.begin(), m_threads, thread);
		(*thread)->add(message);
	} else {
		Thread* thread = new Thread(thread_id);
		thread->add(message);
		m_threads.push_front(thread);
		m_id_to_thread[thread_id] = m_threads.begin();
	}
}

void ThreadList::display() {
	string print_out = "";
	int k = 0;
	for (const auto& thread : m_threads) {
		if (k++ == m_display_size) break;
		print_out = print_out + (*thread).str() + ", ";
	}
	print_out = "[" + (print_out == "" ? print_out : print_out.substr(0, print_out.size() - 2)) + "]";
	cout << print_out << endl;
}