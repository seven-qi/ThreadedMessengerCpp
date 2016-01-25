# ThreadedMessengerCpp
This is a threaded mailing list that will shows the most top k threads in C++


Designs & Ideas

Pointers
For pointer usage in this program, there is a good pratice - using std::unique_ptr rather than raw pointers because unique_ptr has exclusive single ownership of the resourse and will be automatically be deallocated when out of scope. 
For example, in class Thread, I could have used:

list<std::unique_ptr<Message>> m_messages

However, I didn't use that implementation since many companies (especially those with some history) don't use it because of code base hisotry. So I choose the general raw pointer implementation that could fit in any code base. Afterall, we need to adapt what the company has been using and work on it.

Singleton or Factory?
I have thought about creating ThreadList as a Singleton given that one app can only has ThreadList. However, I think we could reuse the implementation for the ThreadList to get MailThreadList, WhatsAppThreadList, MessengerThreadList, etc. So I didn't use singleton.

