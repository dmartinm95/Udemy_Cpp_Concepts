#include <iostream>
using namespace std;

class Parent {
public:
    void speak() {
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

    Brother *pbb = static_cast<Brother *>(ppb);
    // static_cast is just a compile time thing that will get your code working but may be error prone

    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();

    return 0;
}