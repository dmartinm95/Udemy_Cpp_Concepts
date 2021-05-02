#include "Bitmap.h"
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
            double xFractal = (x - WIDTH / 2) / (WIDTH / 2.0);
            double yFractal = (y - HEIGHT / 2) / (HEIGHT / 2.0);

            if (xFractal < min) {
                min = xFractal;
            }

            if (xFractal > max) {
                max = xFractal;
            }
        }
    }

    cout << min << ", " << max << endl;

    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
