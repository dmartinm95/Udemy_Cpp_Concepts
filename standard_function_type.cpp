#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

bool check(string &test) {
    return test.size() == 3;
}

class Check {
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

// Has to accept a reference to a string and return a bool
void run(function<bool(string &)> check) {
    string test = "stars";
    cout << check(test) << endl;
}

int main() {

    int size = 5;

    vector<string> vec{"one", "two", "three"};

    auto lambda = [size](string test) { return test.size() == size; };

    // Pass in a lambda expression
    int count = count_if(vec.begin(), vec.end(), lambda);

    cout << count << endl;

    // Pass in a function pointer
    count = count_if(vec.begin(), vec.end(), check);

    cout << count << endl;

    // Pass in a functor
    count = count_if(vec.begin(), vec.end(), check1);

    cout << count << endl;

    run(lambda);
    run(check1);
    run(check);

    // A handy way to create a type that can refer to anything callable that has a return type and parameters specified
    function<int(int, int)> add = [](int one, int two) { return one + two; };

    cout << add(7, 3) << endl;

    auto multiply = [](double a, double b) { return a * b; };

    cout << multiply(10, 10) << endl;

    int cats = 5;

    // Can make a copy of local variables and update it inside a lambda expression by using the keyword 'mutable'
    [cats]() mutable {
        // Can now update the value passed in by value as it is a copy of the local variable
        cats = 8;
        cout << cats << endl;
    }();

    // But the local variable is still unchanged outside the lambda expression
    cout << cats << endl;

    return 0;
}