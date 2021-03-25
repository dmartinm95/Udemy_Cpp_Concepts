#include <iostream>
#include <map>
using namespace std;

// Custom objects as map values
class Person {
private:
    string name;
    int age;

public:
    // Default constructor
    Person() : name(""), age(0) {}

    // Constructor with parameters
    Person(string name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person &other) {
        cout << "Copy constructor running!" << endl;
        name = other.name;
        age = other.age;
    }

    void print() const {
        cout << name << ": " << age << endl;
    }

    // Overloading operator '<' for our object class
    // const is used so that both objects are not changed when using this method
    bool operator<(const Person &other) const {

        if (name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }
};

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

    // Map using custom object as the value
    map<int, Person> people;

    people[0] = Person("Mike", 40);
    people[1] = Person("Vicky", 30);
    people[2] = Person("Raj", 20);

    people.insert(make_pair(55, Person("Bob", 45)));
    people.insert(make_pair(55, Person("Sue", 24)));

    cout << "Using custom objects in maps" << endl;

    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->first << " - ";
        it->second.print();
    }

    string test1 = "Mike";
    string test2 = "Bob";

    bool test = test1 < test2;
    cout << test << endl;

    // Map using custom objects as the key
    map<Person, int> people2;
    people2[Person("Mike", 40)] = 40;
    people2[Person("Mike", 444)] = 123;
    people2[Person("Sue", 30)] = 30;
    people2[Person("Raj", 20)] = 20;

    // Need to create our custom < operator for our class since maps get ordered automatically

    cout << "Using custom objects in keys" << endl;

    for (map<Person, int>::iterator it = people2.begin(); it != people2.end(); it++) {
        cout << it->second << ": " << flush;
        it->first.print();
    }

    return 0;
}