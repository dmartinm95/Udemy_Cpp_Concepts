#include <functional>
#include <iostream>
using namespace std;
using namespace placeholders;

class Test {
public:
    int add(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }

    void multiply(int a, int b, string text) {
        cout << text << endl;
        cout << "Multiplying " << a << " x " << b << ": " << a * b << endl;
    }
};

int run(function<int(int, int)> func) {
    return func(7, 3);
}

void runMult(function<void(int, int, string)> func) {
    func(10, 11, "Hi there");
}

int main() {

    Test test;

    // Bind allows you to create aliases to functions, a bit like function pointers

    // auto calculate = bind(add, 3, 4, 5);

    // Can also specify arguments using placeholders
    // auto calculate = bind(add, _1, _2, _3);

    // Can also switch the order the arguments are passed in
    // auto calculate = bind(add, _2, _3, _1);

    // Can also mix and match and bind to a method of a class
    auto calculate = bind(&Test::add, test, _2, 100, _1);

    cout << run(calculate) << endl;

    auto mult = bind(&Test::multiply, test, _2, _1, _3);

    mult(5, 4, "Hi There!");

    runMult(mult);

    return 0;
}