#ifndef BITMAP_H_
#define BITMAP_H_

#include <cstdint>
#include <memory>
#include <string>
using namespace std;

namespace caveofprogramming {

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr}; // Points to a block of memory for all pixels

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool write(string filename);
    virtual ~Bitmap();
};

} // namespace caveofprogramming

#endif