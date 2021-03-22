#include <iostream>
#include <map>
using namespace std;

int main() {

    // Maps use key value pairs to store information
    // All keys are unique
    map<string, int> ages;

    // Inserting values to maps
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    // Insert using pairs
    ages.insert(pair<string, int>("Peter", 100));

    // Insert using built-in function make_pair()
    ages.insert(make_pair("Joe", 44));

    // Outputing values from maps
    cout << ages["Mike"] << endl;

    // Test if a value is in the map
    if (ages.find("Vicky1") != ages.end()) {
        cout << "Found Vicky" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // Iterating through map values
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;

    // Another way to iterate though map values using pairs
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;
        cout << age.first << ": " << age.second << endl;
    }

    return 0;
}