#include "stdafx.h"
#include "CppUnitTest.h"
#include "ThreadList.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ThreadedMessengerTest
{
	TEST_CLASS(ThreadListTest)
	{
	public:
		
		TEST_METHOD(display_size)
		{
			ThreadList* threadlist = new ThreadList(3);
			Assert::AreEqual(threadlist->display_size(), 3);
			delete threadlist;
		}

		TEST_METHOD(display)
		{
			ThreadList* threadlist = new ThreadList(3);
			string str = "[]\n";
			streambuf* old_cout_stream_buf = cout.rdbuf();
			ostringstream str_cout;
			cout.rdbuf(str_cout.rdbuf());
			threadlist->display();
			cout.rdbuf(old_cout_stream_buf);
			Assert::AreEqual(str_cout.str(), str);
			delete threadlist;
		}

		TEST_METHOD(add)
		{
			// Create new threadlist with k == 3.
			ThreadList* threadlist = new ThreadList(3);

			// Check nullptr.
			Assert::AreEqual(1, threadlist->add(nullptr, 1));

			// Check invalid id.
			Message* message = new Message(11, "This is head of message 11", "This is content of message 11");
			Assert::AreEqual(1, threadlist->add(message, NULL));

			// Add message to non-existing thread).
			int ret = threadlist->add(message, 1);
			Assert::AreEqual(0, ret);

			string str = "[1(11)]\n";
			streambuf* old_cout_stream_buf = cout.rdbuf();
			ostringstream str_cout;
			cout.rdbuf(str_cout.rdbuf());
			threadlist->display();
			cout.rdbuf(old_cout_stream_buf);
			Assert::AreEqual(str, str_cout.str());

			message = new Message(21, "This is head of message 21", "This is content of message 21");
			threadlist->add(message, 2);
			str = "[2(21), 1(11)]\n";
			old_cout_stream_buf = cout.rdbuf();
			str_cout.clear();
			str_cout.str("");
			cout.rdbuf(str_cout.rdbuf());
			threadlist->display();
			cout.rdbuf(old_cout_stream_buf);
			Assert::AreEqual(str, str_cout.str());

			// Add message to existing thread.
			message = new Message(12, "This is head of message 12", "This is content of message 12");
			threadlist->add(message, 1);
			str = "[1(12, 11), 2(21)]\n";
			old_cout_stream_buf = cout.rdbuf();
			str_cout.clear();
			str_cout.str("");
			cout.rdbuf(str_cout.rdbuf());
			threadlist->display();
			cout.rdbuf(old_cout_stream_buf);
			Assert::AreEqual(str_cout.str(), str);

			// Add message to let threadlist has more than k threads.
			// This also serves as a test for display() to see if it only shows k threads.
			// But since display() also depends on add() if there is any message in the threadlist,
			// so we check this after we check add().
			message = new Message(31, "This is head of message 31", "This is content of message 31");
			threadlist->add(message, 3);
			message = new Message(41, "This is head of message 41", "This is content of message 41");
			threadlist->add(message, 4);
			str = "[4(41), 3(31), 1(12, 11)]\n";
			old_cout_stream_buf = cout.rdbuf();
			str_cout.clear();
			str_cout.str("");
			cout.rdbuf(str_cout.rdbuf());
			threadlist->display();
			cout.rdbuf(old_cout_stream_buf);
			Assert::AreEqual(str_cout.str(), str);
			
			// Deallocate
			delete threadlist;
		}

	};
}