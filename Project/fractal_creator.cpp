#include "Bitmap.h"
#include <iostream>
using namespace std;
using namespace caveofprogramming;

int main() {

    Bitmap bitmap(800, 600);

    bitmap.write("test4.bmp");

    cout << "Finished." << endl;
    return 0;
}
