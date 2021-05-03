#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
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

    ZoomList zoomList(WIDTH, HEIGHT);

    // We can change the scaling to zoom in or out
    zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));

    // Can input any point that we want to zoom in at
    zoomList.add(Zoom(295, HEIGHT - 202, 0.1));

    zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            pair<double, double> coords = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

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
