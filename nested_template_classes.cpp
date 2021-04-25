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

    Iterator begin() {
        return Iterator(0, *this);
    }

    Iterator end() {
        return Iterator(m_size, *this);
    }
};

template <class T>
class Ring<T>::Iterator {
private:
    int m_pos;
    Ring &m_ring;

public:
    Iterator(int pos, Ring &aRing) : m_pos(pos), m_ring(aRing) {
    }

    // Overloading post-fix increment needs to have argument (no argument is for pre-fix increment operator)
    Iterator &operator++(int) {
        m_pos++;
        return *this;
    }

    // Overloading the pre-fix operator
    Iterator &operator++() {
        m_pos++;
        return *this;
    }

    T &operator*() {
        return m_ring.get(m_pos);
    }

    bool operator!=(const Iterator &other) const {
        return m_pos != other.m_pos;
    }
};

int main() {

    Ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");

    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }

    cout << endl;

    // Making class iterable
    for (Ring<string>::Iterator it = textring.begin(); it != textring.end(); it++) {
        cout << *it << endl;
    }

    cout << endl;

    for (string value : textring) {
        cout << value << endl;
    }
    return 0;
}