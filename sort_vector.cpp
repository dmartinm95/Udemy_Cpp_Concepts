#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Test {
    int id;
    string name;

public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}
    void print() {
        cout << id << ": " << name << endl;
    }

    // bool operator<(const Test &other) const {
    //     return name < other.name;
    // }

    // When we find a function with this prototype we will make it a friend and
    // will have access to private members
    friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
    return a.name < b.name;
}

int main() {
    vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    // Can also pass in a function pointer that will do the comparison between two custom objects
    sort(tests.begin(), tests.end(), comp);

    for (int i = 0; i < tests.size(); i++) {
        tests[i].print();
    }

    return 0;
}