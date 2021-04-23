#include <iostream>
using namespace std;

// Abstract classes and pure virtual functions
// You want to have a base class but doesn't make sense to instantiate it

// Abstract class is a class containing methods which have no implementation (they are pure virtual methods)
// A class that has pure virtual functions it is called an abstract class, they cannot be instantiated it
class Animal {
public:
    // Setting it = 0 means that there is no implementation == pure virtual function
    virtual void speak() = 0;

    virtual void run() = 0;
};

class Dog : public Animal {
public:
    virtual void speak() {
        cout << "Woof!" << endl;
    }
};

class Labrador : public Dog {
public:
    Labrador() {
        cout << "new labrador" << endl;
    }
    virtual void run() {
        cout << "Labrador running" << endl;
    }
};

void test(Animal &a) {
    a.run();
}

int main() {

    // Cannot do -> Animal animal; because it is an abstract class with pure virtual functions

    Labrador lab;
    lab.run();
    lab.speak();

    Labrador labs[5];

    // Can create an array of pointers to the super class and put all kinds of sub classes in there
    Animal *animals[5];
    animals[0] = &lab;

    animals[0]->speak();

    test(lab);

    return 0;
}