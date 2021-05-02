#include "Mandelbrot.h"
#include <complex>
using namespace std;

namespace caveofprogramming {
Mandelbrot::Mandelbrot() {
}

Mandelbrot::~Mandelbrot() {}

int Mandelbrot::getIterations(double x, double y) {

    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        z = z * z + c;

        if (abs(z) > 2) {
            // If it exceeds 2, the sequence will escape to infinity and is not bounded and not part of the mandelbrot set
            break;
        }

        // The absolute value of z must remain at or below 2 for c to be in the Mandelbrot set.

        iterations++;
    }

    return iterations;
}

} // namespace caveofprogramming