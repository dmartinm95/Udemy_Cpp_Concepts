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

int main() {

    // C++ can do something called "return value optimization" which involves eliding or getting rid of extra copies of objects
    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}