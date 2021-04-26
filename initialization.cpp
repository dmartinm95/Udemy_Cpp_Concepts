#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

class Test {

public:
    Test(initializer_list<string> texts) {
        for (auto value : texts) {
            cout << value << endl;
        }
    }

    void print(initializer_list<string> texts) {
        for (auto value : texts) {
            cout << value << endl;
        }
    }
};

class Test1 {
    int id{3};
    string name{"Mike"};

public:
    Test1() = default;

    Test1(const Test1 &other) = default;

    // To remove copy constructor can use the keword 'delete' instead of 'default'
    // Test1(const Test1 &other) = delete;

    Test1 &operator=(const Test1 &other) = default;

    Test1(int id) : id(id) {
    }

    void print() {
        cout << id << ": " << name << endl;
    }
};

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

    cout << endl;

    // Initializer lists
    vector<int> numbers3{1, 2, 3, 4, 5};
    cout << numbers3[2] << endl;

    Test test{"apple", "orange", "banana"};

    test.print({"one", "two", "three", "four"});

    cout << endl;

    // Object initialization, default and delete
    Test1 test1;
    test1.print();

    Test1 test2(77);
    test2.print();

    return 0;
}