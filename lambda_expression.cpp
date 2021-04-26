#include <iostream>
using namespace std;

void test(void (*pFunc)()) {
    // A function pointer called pFunc to a function which has a void return type and has no parameters
    pFunc();
}

void testGreet(void (*greet)(string name)) {
    greet("Bob");
}

void runDivide(double (*divide)(double a, double b)) {
    cout << divide(20.0, 5.0) << endl;
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

    // Lambda parameters and return types
    auto pGreet = [](string name) { cout << "Hello " << name << endl; };

    pGreet("Mike");

    testGreet(pGreet);

    // Can specify return type by using trailing return type
    auto pDivide = [](double a, double b) -> double {
        if (b == 0.0) {
            return 0;
        }
        return a / b;
    };

    cout << pDivide(10.0, 5.0) << endl;
    cout << pDivide(10.0, 0) << endl;

    runDivide(pDivide);

    return 0;
}