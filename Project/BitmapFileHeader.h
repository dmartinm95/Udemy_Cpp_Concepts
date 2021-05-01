#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

// Need to avoid extra optimization padding
#pragma pack(push, 2) // Aligns structure members on 2-byte boundaries

namespace caveofprogramming {

struct BitmapFileHeader {

    // Need two bytes containing the numeric representation of the letters 'B' and 'M' which tells the application that opens this file that it is a bitmap file
    char header[2]{'B', 'M'};

    // Size of the final file, needs to be precisely 32-bit in size
    int32_t finalSize;

    int32_t reserved{0};

    // How long into the file the actual data begins
    int32_t dataOffset;
};
#pragma pack(pop)

} // namespace caveofprogramming
#endif /* BITMAPFILEHEADER_H_ */