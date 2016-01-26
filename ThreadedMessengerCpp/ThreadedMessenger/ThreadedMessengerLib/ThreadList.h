/**
 * @file	ThreadList.h
 *
 * @brief	Declares the ThreadList class.
 */

#include <list>
#include <unordered_map>
#include "ThreadedMessenger.h"
#include "Thread.h"

/**
 * @class	ThreadList
 *
 * @brief	List of threads. It can add a message 
 * 			and maintain the most recent k threads to display.
 *
 * @author	Sevensevens
 * @date	1/24/2016
 */

class ThreadList {
public:

	/**
	 * @fn	ThreadList::ThreadList(int k);
	 *
	 * @brief	Constructor. Initialize a ThreadList object with its display size.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @param	k	The number of the most recent threads to display.
	 */

	ThreadList(int k);

	/**
	 * @fn	ThreadList::~ThreadList();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 */

	~ThreadList();

	/**
	 * @fn	int ThreadList::display_size();
	 *
	 * @brief	Returns the display size of the thread list.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	An int.
	 */

	int display_size();

	/**
	 * @fn	int ThreadList::set_display_size();
	 *
	 * @brief	Sets display size.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	An int.
	 */

	int set_display_size(int k);

	/**
	 * @fn	int ThreadList::add(Message* message, unsigned int thread_id);
	 *
	 * @brief	Adds a message to its thread, 
	 * 			and put that thread to the front of the queue.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @param [in,out]	message	If non-null, the message.
	 * @param	thread_id	   	Identifier for the thread.
	 *
	 * @return	An int. Returns 0 if success, otherwise 1.
	 */

	int add(Message* message, unsigned int thread_id);

	/**
	 * @fn	void ThreadList::display();
	 *
	 * @brief	Displays the top k threads.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 */

	void display();

private:
	/** @brief	The number of threads the threalist will display. */
	int m_display_size;
	/** @brief	The list of threads that keep the most recent thread at front. */
	list<Thread*> m_threads;
	/** @brief	The hash map that maps the thread_id to the Thread object. */
	unordered_map<int, list<Thread*>::iterator> m_id_to_thread;
	/** @brief	The hared logger. */
	std::shared_ptr<spdlog::logger> m_logger;
};