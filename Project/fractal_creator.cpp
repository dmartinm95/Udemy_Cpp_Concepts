#include "Bitmap.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>
using namespace std;
using namespace caveofprogramming;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Want to get xFractal to range between [-1, 1] by using offsets and scaling
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT; // making the scaling the same to avoid stretching the image

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            fractal[y * WIDTH + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
        }
    }

    int total = 0;

    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];

            if (iterations != Mandelbrot::MAX_ITERATIONS) {

                double hue = 0.0;

                // Changing the color proportional to the number of iterations
                for (int i = 0; i <= iterations; i++) {
                    hue += ((double)histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
