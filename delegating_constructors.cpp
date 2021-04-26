#include <iostream>
using namespace std;

class Parent {
    int dogs;
    string text;

public:
    // Delegating constructors
    Parent() : Parent("Hello") {
        dogs = 5;
        cout << "No parameter parent constructor" << endl;
    }

    Parent(string text) {
        dogs = 5;
        this->text = text;
        cout << "string parameter constructor" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
    }
};

int main() {

    Parent parent("HELLO");
    Child child;
    return 0;
}