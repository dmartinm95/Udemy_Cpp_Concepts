#include <iostream>
using namespace std;

// super class (base class)
class Parent {
private:
    int one;

public:
    Parent() : one(0) {
    }

    Parent(const Parent &other) : one(0) {
        one = other.one;
        cout << "copy parent" << endl;
    }

    // A C++ virtual function is a member function in the base class that you redefine in a derived class
    virtual void print() {
        cout << "parent" << endl;
    }

    virtual ~Parent() {}
};

// sub-class of Parent
class Child : public Parent {
private:
    int two;

public:
    Child() : two(0) {
    }
    void print() {
        cout << "child" << endl;
    }
};

// Object slicing is where you assign an object of a derived class to an instance of a base class, thereby losing part of the information - some of it is "sliced" away
int main() {

    Child c1;
    Parent &p1 = c1;

    p1.print();

    // Object slicing, "two" from Child gets sliced away when using the copy constructor in the base class Parent
    // We are 'upcasting' a child object to a parent type
    Parent p2 = Child();
    p2.print();

    return 0;
}