#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Vectors are resizable
    // .end() method returns an iterator to the element after the last inserted element
    vector<string> strings;
    vector<int> nums;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    // Iterate through a vector
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    // Insert 100 numbers into vector
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }

    // Declaring an iterator
    vector<string>::iterator it = strings.begin();

    // Another way to iterate through a vector using iterators
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    // Output the numbers in descending order
    for (vector<int>::iterator it = nums.end() - 1; it != nums.begin(); it--) {
        cout << *it << endl;
    }

    vector<double> numbers(0);

    // Size refers to the actual number of elements in the vector
    cout << "Size: " << numbers.size() << endl;

    // Capacity refers to the internal memory reserved for the array/vector
    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for (int i = 0; i < 10000; i++) {
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }
        numbers.push_back(i);
    }

    // .resize() changes the size of the vector
    // .reserve() changes the capacity of the vector
    numbers.resize(100);

    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    return 0;
}