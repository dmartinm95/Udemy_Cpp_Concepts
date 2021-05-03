#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Bitmap.h"
#include "Mandelbrot.h"
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

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();

    void calculateIterations();
    void calculateTotalIterations();
    void drawFractal();
    void addZoom(const Zoom &zoom);
    void writeBitmap(string name);
};

} // namespace caveofprogramming

#endif