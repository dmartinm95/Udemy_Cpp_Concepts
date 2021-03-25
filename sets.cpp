#include <iostream>
#include <set>

using namespace std;

class Test {

    int id;
    string name;

public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}

    void print() const {
        cout << id << ": " << name << endl;
    }

    bool operator<(const Test &other) const {
        return name < other.name;
    }
};

// Set only stores unique elements. It will not insert elements with the same key
// Really good for getting rid of duplicates and finding the unique elements
int main() {

    set<int> numbers;

    numbers.insert(5);
    numbers.insert(10);
    numbers.insert(14);
    numbers.insert(5);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    // Finding a key from a set
    set<int>::iterator itFind = numbers.find(5);

    if (itFind != numbers.end()) {
        cout << "Found: " << *itFind << endl;
    }

    // .count will return 0 or 1 depending it that key exists
    if (numbers.count(10)) {
        cout << "Number Found." << endl;
    }

    cout << endl;

    // Using custom objects inside sets
    set<Test> tests;

    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(444, "Joe"));
    tests.insert(Test(20, "Sue"));

    for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }

    return 0;
}