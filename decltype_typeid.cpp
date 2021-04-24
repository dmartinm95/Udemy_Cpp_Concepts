#include <iostream>
#include <typeinfo>
using namespace std;

template <class T, class S>
// When using auto, we need more information about the return type, in C++11 we can use trailing return types '->' along with decltype
auto test(T value1, S value2) -> decltype(value1 + value2) {
    return value1 + value2;
}

int get() {
    return 999;
}

auto test2() -> decltype(get()) {
    return get();
}

int main() {

    string value;

    // typeid is used where the dynamic type or runtime type information of an object is needed
    cout << typeid(value).name() << endl;

    // decltype extracts the type of the variable and assigns it to a variable
    decltype(value) name = "Bob";

    cout << typeid(name).name() << endl;

    cout << name << endl;

    // using auto keyword
    auto numb = 7;
    auto text = "Hello";

    cout << test(5, 6) << endl;

    cout << test2() << endl;

    return 0;
}