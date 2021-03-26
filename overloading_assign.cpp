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

    friend ostream &operator<<(ostream &out, const Test &test) {
        out << test.id << ": " << test.name;
        return out;
    }
};

class Person {

    string firstName;
    string lastName;

public:
    Person() : firstName(""), lastName("") {}
    Person(string firstName, string lastName) : firstName(firstName), lastName(lastName) {}

    void print() {
        cout << firstName << " " << lastName << endl;
    }

    const Person &operator=(const Person &other) {
        cout << "Overloaded operator = running" << endl;
        firstName = other.firstName;
        lastName = other.lastName;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Person &person) {
        out << person.firstName << " " << person.lastName;
        return out;
    }
};

int main() {
    // Example of = operator overloading
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;

    test2.print();

    Test test3;

    // The return object from the = operator should be a reference to a Test object
    test3.operator=(test2);

    test3.print();

    cout << endl;

    // Copy initialization, uses copy constructor instead of assignment operator
    Test test4 = test1;
    test4.print();

    cout << endl
         << endl;

    // Example of << operator overloading
    // Need to return a reference to ostream object
    Test test5(1, "Mike");
    Test test6(20, "Bob");
    test5.print();

    // Would be nice to be able to do this instead: cout << test5 << endl;
    cout << test5 << test6 << endl;

    cout << endl
         << endl;

    Person person1("Mike", "Lee");
    Person person2("May", "Tree");
    Person person3("James", "Tang");

    person1.print();
    person2.print();
    person3.print();

    person2 = person1;
    person2.print();

    cout << person1 << " " << person2 << " " << person3 << endl;

    return 0;
}