#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Vectors are resizable
    // .end() method returns an iterator to the element after the last inserted element
    vector<string> strings;
    vector<int> numbers;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    // Iterate through a vector
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    // Insert 100 numbers into vector
    for (int i = 0; i < 100; i++) {
        numbers.push_back(i);
    }

    // Declaring an iterator
    vector<string>::iterator it = strings.begin();

    // Another way to iterate through a vector using iterators
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    // Output the numbers in descending order
    for (vector<int>::iterator it = numbers.end() - 1; it != numbers.begin(); it--) {
        cout << *it << endl;
    }

    return 0;
}