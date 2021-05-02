#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming {

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    // Get a pointer to a whole memory block that represents the whole screen
    uint8_t *pPixel = m_pPixels.get();

    // Move the pointer to the correct pixel using pointer arithmetic
    pPixel += (y * 3) * m_width + (x * 3);

    // Reversed order because the bitmap is in little endian format
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;

    // 0xFF8833: 33 is the least significant byte, FF is the most significant byte
}

bool Bitmap::write(string filename) {
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    // final size = 14 + 40 + (800*600*3) = 1440054
    fileHeader.finalSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); // After this size offset, our data starts

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;

    file.open(filename, ios::out | ios::binary);

    if (!file) {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width * m_height * 3);

    file.close();

    if (!file) {
        return false;
    }

    return true;
}

Bitmap::~Bitmap() {
}

} // namespace caveofprogramming