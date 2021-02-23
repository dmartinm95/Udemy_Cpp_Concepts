#include <fstream>
#include <iostream>
using namespace std;

/* Using Files:
- Writing to files
- Reading to files 
- Parsing text files
- Structs and Padding
- Reading and writing binary files
*/

int main() {
    string outputFileName = "text.txt";
    string outFileName = "text2.txt";

    ofstream outputFile;

    // Could also declare a file as
    fstream outFile;

    // Need to specify if it is an input file or output file
    outFile.open(outFileName, ios::out);

    int numLines = 10;

    outputFile.open(outputFileName);

    if (outputFile.is_open()) {
        for (int i = 0; i < numLines; i++) {
            outputFile << i << ". This is line # " << i << "." << endl;
        }
        outputFile.close();

    } else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    outFile.close();

    return 0;
}