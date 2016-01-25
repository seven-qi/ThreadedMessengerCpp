/**
 * @file	Message.h
 *
 * @brief	Declares the message class.
 */

#include <string>
#include <memory>
#include "spdlog\spdlog.h"

using namespace std;

/**
 * @class	Message
 *
 * @brief	A message with id, head and content.
 *
 * @author	Sevensevens
 * @date	1/24/2016
 */

class Message {
public:

	/**
	 * @fn	Message::Message(unsigned int id, const string& head, const string& content);
	 *
	 * @brief	Constructor. Initialize a Message object with its id, head, and content.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @param	id	   	The identifier.
	 * @param	head   	The head.
	 * @param	content	The content.
	 */

	Message(unsigned int id, const string& head, const string& content);

	/**
	 * @fn	const unsigned int Message::id();
	 *
	 * @brief	Gets the id of the Message object.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	An int.
	 */

	const unsigned int id();

	/**
	 * @fn	const string& Message::head();
	 *
	 * @brief	Gets the head.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string.
	 */

	const string& head();

	/**
	 * @fn	const string& Message::content();
	 *
	 * @brief	Gets the content.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string&amp;
	 */

	const string& content();

	/**
	* @fn	string Message::str();
	*
	* @brief	Uses the id as the string representation of the Message object.
	*
	* @author	Sevensevens
	* @date	1/24/2016
	*
	* @return	A string.
	*/

	string str();

private:
	/** @brief	The unique identifier of a Message object. */
	const unsigned int m_id;
	/** @brief	The head of the message. */
	const string& m_head;
	/** @brief	The content of the message. */
	const string& m_content;
	/** @brief	The shared logger. */
	std::shared_ptr<spdlog::logger> m_logger;
};