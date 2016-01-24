#include <list>
#include <unordered_map>
#include "Thread.h"

class ThreadList {
public:
	ThreadList(int k);
	void add(Message* message, unsigned int thread_id);
	void display();

private:
	int m_display_size;
	list<Thread*> m_threads;
	unordered_map<int, list<Thread*>::iterator> m_id_to_thread;
};