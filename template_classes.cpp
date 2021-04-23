#include <iostream>
using namespace std;

// Template classes
// Allows you to design classes that work with types of variables that the user can specify

template <class T>
class Test {
private:
    T obj;

public:
    Test(T obj) {
        this->obj = obj;
    }

    void print() {
        cout << obj << endl;
    }
};

// Template functions

template <class K>
void printType(K n) {
    cout << "Template version: " << n << endl;
}

void printType(int value) {
    cout << "Non-template version: " << value << endl;
}

int main() {
    Test<string> test1("Hello");

    test1.print();

    printType<string>("World!");

    printType("Hi There");

    // Uses type inference to use the template version of the function
    printType<>(6);

    printType(5);

    return 0;
}