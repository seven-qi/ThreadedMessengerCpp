#include "stdafx.h"
#include "Message.h"

Message::Message(unsigned int id, const string& head, const string& content) :
m_id(id), m_head(head), m_content(content) {};

const unsigned int Message::id() {
	return m_id;
}

const string Message::head() {
	return m_head;
}

const string Message::content() {
	return m_content;
}

string Message::str() {
	return to_string(m_id);
}