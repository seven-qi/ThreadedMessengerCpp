#include "stdafx.h"
#include "CppUnitTest.h"
#include "Thread.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ThreadedMessengerTest
{
	TEST_CLASS(ThreadTest)
	{
	public:
		
		TEST_METHOD(id)
		{
			spdlog::drop_all();
			Thread* thread = new Thread(1);
			unsigned int id = 1;
			Assert::AreEqual(id, thread->id());
			delete thread;
		}

		TEST_METHOD(str)
		{
			Thread* thread = new Thread(1);
			string correct_str = "1()";
			Assert::AreEqual(correct_str, thread->str());
			delete thread;
		}

		TEST_METHOD(add)
		{
			// Create thread and message
			Thread* thread = new Thread(1);
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			
			// Check nullptr.
			Assert::AreEqual(1, thread->add(nullptr));

			// Check message pointer.
			thread->add(message);
			string correct_str = "1(1)";
			Assert::AreEqual(correct_str, thread->str());

			delete thread;
		}
	};
}