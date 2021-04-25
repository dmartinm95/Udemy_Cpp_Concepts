#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Initialization in C++ 98
    int values[] = {1, 4, 5};

    cout << values[0] << endl;

    // Classes by default member values are private
    class C {
    public:
        string text;
        int id;
    };

    C c1 = {"Hello", 7};

    cout << c1.text << endl;

    // Structs by default member values are public
    struct S {
        string text;
        int id;
    };

    S s1 = {"Hello", 7};

    cout << s1.text << endl;

    struct R {
        string text;
        int id;
    } r1 = {"Hello", 7}, r2 = {"Hi", 9};

    cout << r1.text << endl;
    cout << r2.text << endl;

    vector<string> strings;

    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");

    // Initialization in C++ 11
    int value{5};
    cout << value << endl;

    string text{"Hello"};
    cout << text << endl;

    int numbers[]{1, 2, 4};
    cout << numbers[1] << endl;

    int *pInts = new int[3]{1, 2, 3};
    cout << pInts[1] << endl;
    delete pInts;

    int *pSomething = nullptr;
    cout << pSomething << endl;

    struct {
        int value;
        string text;

    } s10{5, "Hi"};

    cout << s10.text << endl;

    vector<string> strings1{"one", "two", "three"};

    cout << strings1[2] << endl;

    return 0;
}