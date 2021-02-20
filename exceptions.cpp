#include <exception>
#include <iostream>
using namespace std;

/* Exceptions:
- They are error handling mechanisms
- Also to detect error conditions
- Exceptions get thrown all the way out of what we call "Call Stack"
- Exceptions can also be thrown from constructors in classes, e.g: when trying to allocate too much memory on a char *
*/

/* Exception catching order
- Must be careful to catch your exceptions with your subclasses before any of your parent classes otherwise they are useless 
- Catch subclasses before the parent classes because of polymorphism 
*/

// Custom exception inherited from exception class
class MyException : public exception {
public:
    virtual const char *what() const throw() {
        return "Something bad happened!";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

void mightGoWrong() {
    bool error1 = false;
    bool error2 = false;

    // As soon as a function throws an error, it exists that function
    if (error1) {
        throw "Something went wrong.";
    }

    if (error2) {
        throw string("Something else went wrong.");
    }
}

void usesMightGoWrong() {
    mightGoWrong();
}

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = false;

    if (error1Detected) {
        throw bad_alloc();
    }

    if (error2Detected) {
        throw exception();
    }
}

int main() {

    try {
        goesWrong();
    } catch (bad_alloc &e) {
        cout << "Catching bad_alloc: " << e.what() << endl;
    } catch (exception &e) {
        cout << "Catching exception: " << e.what() << endl;
    }

    Test test;

    try {
        test.goesWrong();
    } catch (MyException &e) {
        cout << e.what() << endl;
    }

    // try-catch block catches the exception thrown by the program
    // allows to gracefully end the program
    try {
        usesMightGoWrong();
    } catch (int e) {
        cout << "Error code: " << e << endl;
    } catch (char const *e) {
        cout << "Error msg: " << e << endl;
    } catch (string &e) {
        cout << "String error message: " << e << endl;
    }

    cout << "Still running program" << endl;

    return 0;
}