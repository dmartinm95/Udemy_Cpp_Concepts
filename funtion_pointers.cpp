#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void test() {
    cout << "Hello" << endl;
}

void print(int value1, int value2, string name) {
    cout << "Hi " << name << endl;
    cout << "Printing value1: " << value1 << endl;
    cout << "Printing value2: " << value2 << endl;
}

bool match(string test) {
    return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*pMatch)(string test)) {
    int tally = 0;
    for (int i = 0; i < texts.size(); i++) {
        if (pMatch(texts[i])) {
            tally++;
        }
    }

    return tally;
}

int main() {
    test();

    // This is a variable called pTest which is a pointer to a function with a void return type and no parameters
    void (*pTest)();

    // We can miss out on this address symbol because the name of the function is a pointer to that function
    pTest = &test;

    // We need to make sure that the dereference operator applies to this function name before the brackets operator applies
    (*pTest)();

    // An alternative way to create and use function pointers
    void (*pTest2)();
    pTest2 = test;
    pTest2();

    // For functions with arguments, need to specify the type of the arguments
    void (*pPrint)(int, int, string) = print;
    pPrint(8, 16, "Diego");

    // Using function pointers

    cout << endl;
    cout << "Using function pointers" << endl;
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << match("one") << endl;

    cout << count_if(texts.begin(), texts.end(), match) << endl;

    cout << countStrings(texts, match) << endl;

    return 0;
}