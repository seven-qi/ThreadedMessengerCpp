/**
 * @file	Thread.h
 *
 * @brief	Declares the Tthread class.
 */

#include <list>
#include "Message.h"

/**
 * @class	Thread
 *
 * @brief	A thread that has a queue of Message object,
 * 			with the most recent message at the front.
 *
 * @author	Sevensevens
 * @date	1/24/2016
 */

class Thread {
public:

	/**
	 * @fn	Thread::Thread(unsigned int id);
	 *
	 * @brief	Constructor. Initialize a Thread object with its id.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @param	id	The identifier.
	 */

	Thread(unsigned int id);

	/**
	 * @fn	const unsigned int Thread::id();
	 *
	 * @brief	Gets the id of the Thread object.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	An int.
	 */

	const unsigned int id();

	/**
	 * @fn	void Thread::add(Message* message);
	 *
	 * @brief	Adds a message to the front of the thread's message queue.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @param [in,out]	message	If non-null, the message to be added.
	 */

	void add(Message* message);

	/**
	 * @fn	string Thread::str();
	 *
	 * @brief	Gets the string representation of the Thread object.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string.
	 */

	string str();

private:
	/** @brief	The unique identifier of the thread. */
	const unsigned int m_id;
	/** @brief	The messages queue that keep the most recent message at front. */
	list<Message*> m_messages;
};