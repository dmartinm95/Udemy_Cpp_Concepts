#include <iostream>
using namespace std;

void test() {
    cout << "Hello" << endl;
}

void print(int value1, int value2, string name) {
    cout << "Hi " << name << endl;
    cout << "Printing value1: " << value1 << endl;
    cout << "Printing value2: " << value2 << endl;
}

int main() {
    test();

    // This is a variable called pTest which is a pointer to a function with a void return type and no parameters
    void (*pTest)();

    // We can miss out on this address symbol because the name of the function is a pointer to that function
    pTest = &test;

    // We need to make sure that the dereference operator applies to this function name before the brackets operator applies
    (*pTest)();

    // An alternative way to create and use function pointers
    void (*pTest2)();
    pTest2 = test;
    pTest2();

    // For functions with arguments, need to specify the type of the arguments
    void (*pPrint)(int, int, string) = print;
    pPrint(8, 16, "Diego");

    return 0;
}