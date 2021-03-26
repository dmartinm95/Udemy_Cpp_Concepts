#include <iostream>

using namespace std;

class Test {
private:
    int id;
    string name;

public:
    // Default constructor
    Test() : id(0), name("") {}

    // Constructor
    Test(int id, string name) : id(id), name(name) {}

    void print() {
        cout << id << ": " << name << endl;
    }

    // Copy constructor
    Test(const Test &other) {
        cout << "Copy constructor running" << endl;
        // Could also do this, using our overloaded operator=
        // *this = other;
        id = other.id;
        name = other.name;
    }

    // operator= overloading
    const Test &operator=(const Test &other) {

        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;

        return *this;
    }

    //
};

int main() {
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;

    test2.print();

    Test test3;

    // The return object from the = operator should be a reference to a Test object
    // test3 = test2 = test1;

    test3.operator=(test2);

    test3.print();

    cout << endl;

    // Copy initialization, uses copy constructor instead of assignment operator
    Test test4 = test1;
    test4.print();

    return 0;
}