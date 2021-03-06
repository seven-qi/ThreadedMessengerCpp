#include "stdafx.h"
#include "CppUnitTest.h"
#include "Message.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ThreadedMessengerTest
{
	TEST_CLASS(MessageTest)
	{
	public:

		TEST_METHOD(id)
		{
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			unsigned int id = 1;
			Assert::AreEqual(id, message->id());
			delete message;
		}

		TEST_METHOD(head)
		{
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			string head = "This is head of message 1";
			Assert::AreEqual(head, message->head());
			delete message;
		}

		TEST_METHOD(content)
		{
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			string content = "This is content of message 1";
			Assert::AreEqual(content, message->content());
			delete message;
		}

		TEST_METHOD(str)
		{
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			string correct_str = "1";
			Assert::AreEqual(correct_str, message->str());
			delete message;
		}
	};
}