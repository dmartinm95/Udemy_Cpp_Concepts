#include <iostream>
using namespace std;

/* Exceptions:
- They are error handling mechanisms
- Also to detect error conditions
- Exceptions get thrown all the way out of what we call "Call Stack"
- Exceptions can also be thrown from constructors in classes, e.g: when trying to allocate too much memory on a char *
*/

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

int main() {
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