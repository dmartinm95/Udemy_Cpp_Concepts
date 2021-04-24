#include <iostream>
#include <typeinfo>
using namespace std;

// Typeid is used where the dynamic type or runtime type information of an object is needed

int main() {

    string value;

    cout << typeid(value).name() << endl;

    // decltype extracts the type of the variable and assigns it to a variable

    decltype(value) name = "Bob";

    cout << typeid(name).name() << endl;

    cout << name << endl;

    return 0;
}