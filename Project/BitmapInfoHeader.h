#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace caveofprogramming {

// Contains information about the bitmap data
struct BitmapInfoHeader {
    int32_t headerSize{40}; // Actual size of this struct (40 bytes)
    int32_t width;          // Width of the actual bitmap
    int32_t height;         // Height of the actual bitmap
    int16_t planes{1};
    int16_t bitsPerPixel{24}; // Use 3 bytes for each color (RGB), 3 * 8 bits = 24
    int32_t compression{0};
    int32_t dataSize{0}; // Will be set later
    int32_t horizontalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};

} // namespace caveofprogramming

#endif