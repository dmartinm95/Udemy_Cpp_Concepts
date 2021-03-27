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
};

// Left bit shift operator overloading
ostream &operator<<(ostream &out, const Complex &complex) {
    out << "(" << complex.getReal() << ", " << complex.getImaginary() << ")";
    return out;
}

int main() {
    Complex c1(2, 3);

    Complex c2 = c1;

    Complex c3;
    c3 = c2;
    cout << c1 << ": " << c3 << endl;

    return 0;
}