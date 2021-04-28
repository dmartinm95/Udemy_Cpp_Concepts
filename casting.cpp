#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "Parent!" << endl;
    }
};

class Brother : public Parent {
};

class Sister : public Parent {
};

int main() {
    Parent parent;
    Brother brother;

    Parent *ppb = &brother;

    Brother *pBrother = static_cast<Brother *>(&parent); // This won't work unless you cast it but it is not recommended

    Brother *pbb = dynamic_cast<Brother *>(ppb);
    // static_cast is just a compile time thing that will get your code working but may be error prone

    // Using dynamic_cast returns a nullptr to tell us when casting is invalid
    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    } else {
        cout << pbb << endl;
    }

    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();

    return 0;
}