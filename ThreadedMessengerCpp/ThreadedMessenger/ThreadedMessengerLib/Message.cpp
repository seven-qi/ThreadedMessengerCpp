/**
 * @file	Message.cpp
 *
 * @brief	Implements the message class.
 */

#include "stdafx.h"
#include "Message.h"

Message::Message(unsigned int id, const string& head, const string& content) :
m_id(id), m_head(head), m_content(content) {
	m_logger = spdlog::get("file_logger");
	m_logger->info("Creates message_{}.", id);
};

const unsigned int Message::id() {
	return m_id;
}

const string& Message::head() {
	return m_head;
}

const string& Message::content() {
	return m_content;
}

string Message::str() {
	return to_string(m_id);
}