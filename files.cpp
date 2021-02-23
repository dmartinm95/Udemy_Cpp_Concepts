#include <fstream>
#include <iostream>
#include <string>
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
    ofstream outputFile;

    // // Could also declare a file as
    // string outFileName = "text2.txt";
    // fstream outFile;

    // // Need to specify if it is an input file or output file
    // outFile.open(outFileName, ios::out);
    // outFile.close();

    int numLines = 10;

    outputFile.open(outputFileName);

    // Writing to a file
    if (outputFile.is_open()) {
        for (int i = 0; i < numLines; i++) {
            outputFile << i << ". This is line # " << i << "." << endl;
        }
        outputFile.close();

    } else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    // Reading from a file
    ifstream inFile;
    string inFileName = "text2.txt";

    // Opening file for reading
    inFile.open(inFileName, ios::in);

    if (inFile.is_open()) {

        string line;

        // Read the entire file until we reach 'end of file'
        while (!inFile.eof()) {
            // To read line by line use getline
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();
    } else {
        cout << "Cannot open file: " << inFileName << endl;
    }

    return 0;
}