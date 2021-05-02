#include "Bitmap.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <iostream>
using namespace std;
using namespace caveofprogramming;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;
    Bitmap bitmap(WIDTH, HEIGHT);

    // Set a white pixel in the middle of the bitmap
    bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255);

    double min = 999999;
    double max = -999999;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Want to get xFractal to range between [-1, 1] by using offsets and scaling
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT; // making the scaling the same to avoid stretching the image

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

            color = color * color * color;

            bitmap.setPixel(x, y, 0, color, 0);

            if (color < min) {
                min = color;
            }

            if (color > max) {
                max = color;
            }
        }
    }

    cout << min << ", " << max << endl;

    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
