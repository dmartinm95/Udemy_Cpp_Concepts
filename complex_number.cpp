#include <iostream>
using namespace std;

// Complex number class implementation
class Complex {

private:
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary(0) {}

    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Copy constructor
    Complex(const Complex &other) {
        cout << "Copy constructor running" << endl;
        real = other.real;
        imaginary = other.imaginary;
    }

    // Assignment operator overloading
    // The return object is const because we don't want it to change
    // The paramter object is const because we don't want it to change either
    // The overall method is not const, because the values will change for real and imaginary
    const Complex &operator=(const Complex &other) {
        cout << "Assignment operator overloading running" << endl;
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Equal operator overloading
    bool operator==(const Complex &other) {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // Not equal operator overloading
    bool operator!=(const Complex &other) {
        return !(*this == other);
    }
};

// Left bit shift operator overloading
ostream &operator<<(ostream &out, const Complex &complex) {
    out << "(" << complex.getReal() << ", " << complex.getImaginary() << ")";
    return out;
}

// Plus operator overloading
Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

// Plus operator overloading
Complex operator+(const Complex &c1, double d) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

// Plus operator overloading
Complex operator+(double d, const Complex &c1) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

int main() {
    Complex c1(2, 3);
    Complex c2(10, 30);

    Complex c3 = c1 + c2;
    cout << c1 << " + " << c2 << ": " << c3 << endl;

    Complex c4(4, 3);
    Complex c5 = c4 + 7;

    cout << endl;
    cout << c5 << endl;

    Complex c6(1, 1);

    cout << 2.14 + c6 << endl;

    cout << endl;

    cout << 7 + c1 + c2 + 8 + 9 + c5 + c6 << endl;

    // Equality operator overloading
    Complex c7(3, 2);
    Complex c8(3, 1);

    if (c7 == c8) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    if (c7 != c8) {
        cout << "Not Equal" << endl;
    } else {
        cout << "Equal" << endl;
    }

    return 0;
}