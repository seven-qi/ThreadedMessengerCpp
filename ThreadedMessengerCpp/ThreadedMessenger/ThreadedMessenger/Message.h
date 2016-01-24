#include <string>

using namespace std;

class Message {
public:
	Message(unsigned int id, const string& head, const string& content);
	string str();
	const unsigned int id();

	/**
	 * @fn	const string Message::head();
	 *
	 * @brief	Gets the head.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string.
	 */

	const string head();

	/**
	 * @fn	const string Message::content();
	 *
	 * @brief	Gets the content.
	 *
	 * @author	Sevensevens
	 * @date	1/24/2016
	 *
	 * @return	A string.
	 */

	const string content();

private:
	const unsigned int m_id;
	const string m_head;
	const string m_content;
};