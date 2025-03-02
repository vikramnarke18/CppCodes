// Online C++ compiler to run C++ program online
#include <iostream>

#include <thread>
using namespace std;
void taskA(){
   // sleep(1);
    for(int i=0;i<10;i++)
    {
        cout<<"CountA="<<i<<endl;
    }
    
}
void taskB(){
   // sleep(1);
    for(int i=0;i<10;i++)
    {
        cout<<"CountB="<<i<<endl;
    }
    
}

int main() {
    thread t1(taskA);
    thread t2(taskB);
    
    t1.join();
    t2.join();


    return 0;
}


/*Once a thread has started we may need to wait for the thread to finish before
 we can take some action. For instance, if we allocate the task of initializing
  the GUI of an application to a thread, we need to wait for the thread to finish to ensure that the GUI has loaded properly.

To wait for a thread, use the std::thread::join() function. This function makes the
 current thread wait until the thread identified by *this has finished executing.
For instance, to block the main thread until thread t1 has finished we would do:

https://onecompiler.com/cpp/42zfmqdes */


/*In C++, networking protocols are implemented using various libraries and frameworks that facilitate communication over networks. The most fundamental protocols include:

1. Transmission Control Protocol (TCP) and User Datagram Protocol (UDP):

C++ provides support for TCP and UDP through socket programming. The Berkeley sockets API is commonly used for this purpose, allowing developers to establish connections and transmit data over networks. This API supports various protocol families, including IPv4 and IPv6. 
WIKIPEDIA

2. Internet Protocol (IP):

IP is the primary protocol in the Internet Layer of the Internet Protocol Suite and is used for routing packets across network boundaries. In C++, IP functionalities are accessed through socket programming, enabling the development of applications that can communicate over IP networks. 
MEDIUM

3. Secure Networking Protocols:

Secure communication protocols like Transport Layer Security (TLS) and Datagram Transport Layer Security (DTLS) can be implemented in C++ to ensure encrypted data transmission. Proposals like P1861R1 discuss how C++ networking libraries can support these protocols effectively. 
REDDIT

4. Higher-Level Protocols:

While C++ primarily provides low-level access to networking through sockets, higher-level protocols such as HTTP, FTP, and SMTP can be implemented using additional libraries or frameworks. These implementations often build upon the basic socket APIs to provide more abstracted and user-friendly interfaces for network communication. 
PREVAJ -

Implementing Networking Protocols in C++:

Implementing communication protocols in C++ can be achieved by designing flexible and generic architectures. For instance, creating a generic C++ library allows for the implementation of various binary communication protocols using simple declarative statements. 
BINARYCOMMPROTOCOLS_CPP

Understanding and implementing these protocols require a solid grasp of network programming concepts and proficiency in C++. By leveraging the appropriate libraries and frameworks, developers can create robust networked applications tailored to specific communication needs.  */