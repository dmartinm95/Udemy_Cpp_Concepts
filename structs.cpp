#include <fstream>
#include <iostream>
using namespace std;

// Structs are often used for writing to files
// Can't use string type to store data because it stores a pointers that points to somewhere in the heap
// Useful for saving and opening files in applications

// Need to turn off padding on a struct (used for optimization) to avoid getting extra bytes

// Padding align on byte boundary (no padding)
#pragma pack(push, 1)
struct Person {
    char name[50]; // Stores 50 bytes
    int age;       // Stores 4 bytes
    double height; // Stores 8 byes
};

// Turn on padding again for efficiency, so it only affects the struct as desired
#pragma pack(pop)

int main() {

    // Initialize struct
    Person someone = {"Frodo", 220, 0.8};

    // .bin will contain raw data, can't be seen on text editors
    string fileName = "test.bin";

    //// Write binary file
    ofstream outputFile;

    // if using 'fstream' instead of 'ofstream' need to pass in the following: 'ios::binary|ios::out'
    outputFile.open(fileName, ios::binary);

    if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();
    } else {
        cout << "Could not create file: " << fileName << endl;
    }

    //// Read binary file

    Person someoneElse = {};

    ifstream inputFile;

    // if using 'fstream' instead of 'ifstream' need to pass in the following: 'ios::binary|ios::in'
    inputFile.open(fileName, ios::binary);

    if (inputFile.is_open()) {
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();
    } else {
        cout << "Could not read file: " << fileName << endl;
    }

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;

    return 0;
}