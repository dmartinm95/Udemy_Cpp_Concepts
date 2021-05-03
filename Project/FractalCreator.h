#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include "Zoom.h"
#include <string>
using namespace std;

namespace caveofprogramming {

class FractalCreator {
public:
    FractalCreator();
    virtual ~FractalCreator();

    void calculateIterations();
    void drawFractal();
    void addZoom(const Zoom &zoom);
    void writeBitmap(string name);
};

} // namespace caveofprogramming

#endif