# ThreadedMessengerCpp
This is a threaded mailing list that will shows the most top k threads in C++

## Design and Ideas
### Data Structure and Implementation
For the threaded messenger, what we need to do is to be able to store the messages in a thread,
and store threads in a threadlist, all of them should be in the order of insertion time with most recent ones at the top.
#### Messenger Class
Stores the m_id, m_head, and m_content
#### Thread Class
Uses a queue to stor the messages with the most recent ones at the front.
#### ThreadList Class
Inorder to keep track of the insertion order and be able to search the Thread object by its id, we need to use something like OrderedDict in Python and linkedHashmap in JAVA,
whose underlying implementation is a doubly linkedlist with each node as the value as a hash_map. In C++ we we list<> and unordered_map<>.
####
Raw Pointer vs Smart Pointer
For pointer usage in this program, there is a good pratice - using std::unique_ptr rather than raw pointers because unique_ptr has exclusive single ownership of the resourse and will be automatically be deallocated when out of scope. 
For example, in class Thread, I could have used:

```Cpp
list<std::unique_ptr<Message>> m_messages
```

However, I didn't use that implementation since many companies (especially those with some history) don't use it because of code base hisotry. So I choose the general raw pointer implementation that could fit in any code base. Afterall, we need to adapt what the company has been using and work on it.

### OO Design
Singleton vs Factory
I have thought about creating ThreadList as a Singleton given that one app can only has ThreadList. 
However, I think we could reuse the implementation for the ThreadList to get 
MailThreadList, WhatsAppThreadList, MessengerThreadList, etc. So I didn't use singleton.

##Samples
If you load the project in Visual Studio and just run in the debug mode, you should see the sample output:
```
Create a new threadlist that shows only the top 3 threads.
State: 
[]

State: 
[7(13)]

Add (M5, T99)
State: 
[99(5), 7(13)]

Add (M4, T11)
State: 
[11(4), 99(5), 7(13)]

Add (M44, T99)
State: 
[99(44, 5), 11(4), 7(13)]

Add (M1, T11)
State: 
[1(1), 99(44, 5), 11(4)]

Add (M2, T7)
State: 
[7(2, 13), 1(1), 99(44, 5)]

```

## Logging
I use spdlog (https://github.com/gabime/spdlog) to do the logging, but it turns out it's not quite compatible with the VS test framework so I disabled it by default.

## Tests
There is another project test folder, simply choose from the banner in Visual Studio, TEST->Run->All Tests,
or TEST->Run->Analyze Code Coverage to see the code coverage.
You should see almost 100% coverage for the source code. The general coverage is low because of logger source code.

## Documentation
Please check the html folder in the root folder and open the index.html file. You should see a detailed documentation page.
