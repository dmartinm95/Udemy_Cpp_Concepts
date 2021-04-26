#include <iostream>
using namespace std;

void test(void (*pFunc)()) {
    // A function pointer called pFunc to a function which has a void return type and has no parameters
    pFunc();
}

int main() {

    // Lambda expression - sort of a function that has no name
    // Real purpose of this is to pass it into functions
    auto func = []() { cout << "Hello" << endl; };

    // Calling a lambda expression
    func();

    test(func);

    // Can also call it this way
    test([]() { cout << "Hello again" << endl; });

    return 0;
}