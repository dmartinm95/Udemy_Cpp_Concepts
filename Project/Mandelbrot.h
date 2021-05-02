#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace caveofprogramming {

class Mandelbrot {

public:
    // The more iterations, the better the quality of the image but tradeoff on speed
    static const int MAX_ITERATIONS = 1000;

public:
    Mandelbrot();
    virtual ~Mandelbrot();
    static int getIterations(double x, double y);
};

} // namespace caveofprogramming

#endif