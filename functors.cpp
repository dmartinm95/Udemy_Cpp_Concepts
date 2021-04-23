#include <algorithm>
#include <iostream>
using namespace std;

struct Test {
    virtual bool operator()(string &text) = 0;

    virtual ~Test() {}
};

// Functors are objects that can be treated as though they are a function or function pointer
// To create a functor, we create a object that overloads the operator().
struct MatchTest : public Test {

    virtual bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if (test(text)) {
        cout << "Text matches!" << endl;
    } else {
        cout << "No match!" << endl;
    }
}

// A Functor
class increment {
private:
    int num;

public:
    increment(int n) : num(n) {}

    int operator()(int arr_num) const {
        return num + arr_num;
    }
};

int main() {

    MatchTest pred;

    string value = "lion";

    MatchTest m;

    check("lion", m);

    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int to_add = 5;

    // Using a functor, we can add a value to the entire array in one call
    transform(arr, arr + n, arr, increment(to_add));
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}