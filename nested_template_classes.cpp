#include <iostream>
using namespace std;

template <class T>
class Ring {

private:
    int m_pos;
    int m_size;
    T *m_values;

public:
    class Iterator;

public:
    Ring(int size) : m_pos(0), m_size(size), m_values(NULL) {
        m_values = new T[size];
    }

    ~Ring() {
        delete[] m_values;
    }

    int size() {
        return m_size;
    }

    void add(T value) {
        m_values[m_pos] = value;

        m_pos++;

        if (m_pos == m_size) {
            m_pos = 0;
        }
    }

    T &get(int pos) {
        return m_values[pos];
    }
};

template <class T>
class Ring<T>::Iterator {
public:
    void print() {
        cout << "Hello from iterator" << endl;
    }
};

int main() {

    Ring<string>::Iterator it;

    it.print();

    Ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }

    return 0;
}