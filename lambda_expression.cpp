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

void runAdd(double (*add)(double a, double b, double c)) {
    cout << add(4.0, 1000.0, 10.0) << endl;
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

    auto pAdd = [](double a, double b, double c) -> double {
        return a + b + c;
    };

    cout << pAdd(4.5, 1.5, 2.5) << endl;

    runAdd(pAdd);

    // Lambda capture expressions
    int one = 1;
    int two = 2;
    int three = 3;

    // Capture one and two by value
    [one, two]() { cout << "HELLO: " << one << ", " << two << endl; }();

    // Capture all local variables by value
    [=]() { cout << "HELLO: " << one << ", "
                 << two << ", " << three << endl; }();

    // Capture all local variables by value, but capture three by reference
    [=, &three]() { 
        three = 7;
        cout << "HELLO: " << one << ", "
                         << two << ", " << three << endl; }();

    // Capture all local variables by reference
    [&]() { 
        three = 10;
        two = 8;
        one = 9;
        cout << "HELLO: " << one << ", "
                         << two << ", " << three << endl; }();

    return 0;
}