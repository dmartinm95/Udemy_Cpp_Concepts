#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "Zoom.h"
#include "ZoomList.h"
#include <cstdint>
#include <math.h>
#include <memory>
#include <string>

using namespace std;

namespace caveofprogramming {

class FractalCreator {

private:
    int m_width;
    int m_height;
    int m_total{0};
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;

private:
    void calculateIterations();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(string name);

public:
    FractalCreator(int width, int height);
    void addZoom(const Zoom &zoom);
    virtual ~FractalCreator();
    void run(string name);
};

} // namespace caveofprogramming

#endif