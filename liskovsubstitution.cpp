#include <iostream>
using namespace std;

// Base class for all birds
class Bird {
public:
    // All birds can walk
    void walk() {
        cout << "Bird is walking!" << endl;
    }
};

// Derived class for flying birds
class FlyingBird : public Bird {
public:
    // Only flying birds can fly
    void fly() {
        cout << "Bird is flying!" << endl;
    }
};

// Derived class for non-flying birds (like penguins)
class Penguin : public Bird {
public:
    // Penguins can't fly, so they don't have a fly() method
    void swim() {
        cout << "Penguin is swimming!" << endl;
    }
};

int main() {
    FlyingBird fb;
    fb.fly();   // Works fine for flying birds
    fb.walk();  // Flying birds can also walk
    
    Penguin p;
    p.walk();   // Penguins can walk
    p.swim();   // Penguins can swim, but no flying functionality
    
    return 0;
}

/*We have a clear separation of behaviors:

Bird: Base class that all birds inherit from and provides the common behavior of walking.
FlyingBird: Derived class that specializes in adding flying behavior for birds that can fly.
Penguin: Derived class that specializes in non-flying birds and introduces swimming behavior.
Now, if you have a function or code that operates on a Bird object,
 it will only rely on the behavior that all birds share (like walking), and the code won’t incorrectly assume that all birds can fly.

This refactor makes it clear that not all birds can fly, and avoids the issue of trying to call fly() on a Penguin.
 Therefore, it complies with the Liskov Substitution Principle (LSP).*/

 

 /*Interface Segregation Principle (ISP)
The Interface Segregation Principle (ISP) is one of the SOLID principles of object-oriented design.
 It states that a client should 
not be forced to depend on interfaces that it does not use. In other words, a class should 
not have to 
implement methods that it does not need.

In C++, ISP can be implemented by breaking down larger interfaces into smaller, more 
specific interfaces. 
This allows clients to only depend on the specific methods they need, rather than being forced 
to implement unnecessary methods.

Let’s consider an example of a Printer class that can print documents in different formats, 
such as PDF, HTML, and plain text. We could define a single interface for this class that includes 
all possible methods, such as printPDF(), printHTML(), and printPlainText().

class Printer {
public:
  virtual void printPDF() = 0;
  virtual void printHTML() = 0;
  virtual void printPlainText() = 0;
};
However, this interface may not be suitable for all clients. For example, a client that only needs to print plain text documents may not want to implement the printPDF() and printHTML() methods.

To adhere to the ISP, we could break down the Printer interface into smaller interfaces that are specific to each document format.

class Printable {
public:
  virtual void print() = 0;
};

class PDFPrintable : public Printable {
public:
  void print() override;
};

class HTMLPrintable : public Printable {
public:
  void print() override;
};

class PlainTextPrintable : public Printable {
public:
  void print() override;
};
Now, clients can depend on the specific interfaces they need. For example, a client that
 only needs to print plain text documents can depend on the PlainTextPrintable interface.

class PlainTextPrinter {
public:
  void print(PlainTextPrintable& document) {
    document.print();
  }
};
By adhering to the Interface Segregation Principle, we can create more flexible and 
reusable code that is easier to maintain. Clients can depend on smaller interfaces 
that are specific to their needs, rather than being forced to implement unnecessary methods.*/

/*High-level modules should not depend on low-level modules. 
Both should depend on abstractions (interfaces or abstract classes).1
In simpler terms, instead of high-level modules directly depending on low-level modules, both should depend on interfaces. 
This decouples the modules, making the system more flexible, maintainable, and testable.
Direct dependencies create tight coupling, which has several drawbacks:

Rigidity: Changes in low-level modules can force changes in high-level modules.
Fragility: Changes in one part of the system can unexpectedly break other parts.
Immobility: It becomes difficult to reuse modules in different contexts. */