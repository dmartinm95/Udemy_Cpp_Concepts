#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *m_pBuffer;

public:
    Test() {
        cout << "Default constructor" << endl;
        m_pBuffer = new int[SIZE]{};

        // One way to initialize bytes in buffer to zero using memset
        // memset(m_pBuffer, 0, SIZE * sizeof(int));
    }

    Test(int i) {
        cout << "Parameterized constructor" << endl;
        m_pBuffer = new int[SIZE]{};

        for (int i = 0; i < SIZE; i++) {
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other) {
        cout << "Copy constructor" << endl;

        m_pBuffer = new int[SIZE]{};

        memcpy(m_pBuffer, other.m_pBuffer, SIZE * sizeof(int));
    }

    Test &operator=(const Test &other) {
        cout << "Assignment operator" << endl;
        m_pBuffer = new int[SIZE]{};

        memcpy(m_pBuffer, other.m_pBuffer, SIZE * sizeof(int));
        return *this;
    }

    ~Test() {
        cout << "Destructor" << endl;
        delete[] m_pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
}

int global = 100;

int &setGlobal() {
    return global;
}

void check(const Test &value) {
    cout << "lValue function!" << endl;
}

void check(Test &&value) {
    cout << "rValue function!" << endl;
}

int main() {

    // C++ can do something called "return value optimization" which involves eliding or getting rid of extra copies of objects
    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    int value1 = 7;

    // lValue is anything you can take the address of (you cannot take the address value of an rValue)
    // In C++ an lValue is something that points to a specific memory location
    // On the other hand, a rValue is something that doesn't point anywhere (they are temporary and short lived)
    int *pValue1 = &value1;
    // int *pValue2 = &7; // cannot do this

    Test *pTest1 = &test1;
    // Test *pTest2 = &getTest(); // Cannot do this

    int *pValue3 = &++value1; // This works because '++value1' is an lValue
    // int *pValue4 = &value1++; // Cannot do this, because 'value1++' is an rValue

    cout << *pValue3 << endl;

    cout << global << endl;
    setGlobal() = 400; // This would be ok, because setGlobal is returning a reference which points to an existing memory location (the global variable) thus is an lValue.
    cout << global << endl;

    // Lvalue References
    Test &rTest1 = test1;
    // Test &rTest2 = getTest(); // This would not work because getTest() is rValue
    const Test &rTest2 = getTest(); // This will work because const lValue references can in fact bind to rRvalues

    // Rvalue References
    Test &&rTest3 = Test(); // We can bind rValue references (labeled by '&&') to rValues
    check(test1);
    check(getTest());
    check(Test());

    return 0;
}