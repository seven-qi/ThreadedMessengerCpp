#include <list>
#include "Message.h"

class Thread {
public:
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
	 * @param [in,out]	message	If non-null, the message to add.
	 */

	void add(Message* message);

	/**
	 * @fn	string Thread::str();
	 *
	 * @brief	Gets the string representation of the message object.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string.
	 */

	string str();

private:
	const unsigned int m_id;
	list<Message*> m_messages;
};