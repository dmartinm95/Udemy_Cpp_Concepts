#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Test {
    string name;

public:
    Test() : name("") {}
    Test(string name) : name(name) {}
    ~Test() {
        // cout << "Object destroyed" << endl;
    }
    void print() {
        cout << name << endl;
    }
};

// Stack: First In Last Out
// Queue: First In First Out
int main() {

    stack<Test> testStack;
    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    cout << endl;

    // This is invalid code! Object is destroyed
    // Test &test1 = testStack.top();
    // testStack.pop();
    // test1.print();   // Reference refers to destroyed objects

    while (testStack.size() > 0) {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }

    cout << endl;

    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    cout << endl;

    while (testQueue.size() > 0) {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    cout << endl;
    return 0;
}