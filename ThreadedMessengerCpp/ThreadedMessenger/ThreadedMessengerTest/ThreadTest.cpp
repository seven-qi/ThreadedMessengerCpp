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
			Thread* thread = new Thread(1);
			unsigned int id = 1;
			Assert::AreEqual(thread->id(), id);
			delete thread;
		}

		TEST_METHOD(str)
		{
			Thread* thread = new Thread(1);
			string str = "1()";
			Assert::AreEqual(thread->str(), str);
			delete thread;
		}

		TEST_METHOD(add)
		{
			// Create thread and message
			Thread* thread = new Thread(1);
			Message* message = new Message(1, "This is head of message 1", "This is content of message 1");
			
			// Check nullptr.
			Assert::AreEqual(1, thread->add(nullptr));

			// Check message ponter.
			thread->add(message);
			string str = "1(1)";
			Assert::AreEqual(thread->str(), str);
			delete thread;
		}
	};
}