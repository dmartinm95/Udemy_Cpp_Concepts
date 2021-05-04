#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "Zoom.h"
#include "ZoomList.h"
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>

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

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange{false};

private:
    void calculateIterations();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name);
    int getRange(int iterations) const;

public:
    FractalCreator(int width, int height);
    void addRange(double rangeEnd, const RGB &rgb);
    void addZoom(const Zoom &zoom);
    virtual ~FractalCreator();
    void run(string name);
};

} // namespace caveofprogramming

#endif