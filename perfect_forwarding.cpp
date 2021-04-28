#include <iostream>
using namespace std;

// Perfect forwarding:
// If a function template forwards its arguments without changing its lvalue or rvalue characteristics, we call it "perfect forwarding"

class Test {
};

template <typename T>
void call(T &&arg) {
    check(forward<T>(arg));
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}

int main() {

    Test test;

    // Calling the function with an lvalue
    call(test);

    // Calling the function with an rvalue
    call(Test());

    return 0;
}