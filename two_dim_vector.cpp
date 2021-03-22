#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void printTable(vector<vector<int>> table);

int main() {

    // Declaring a 2D vector
    // 13 columns with 13 rows that have been initialized to 0
    vector<vector<int>> grid(13, vector<int>(13, 0));

    int rowIndex = 0;
    int colIndex = 0;

    // Initialize our 12 times table
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (row == 0) {
                grid[row][col] = rowIndex;
            }
            if (col == 0) {
                grid[row][col] = colIndex;
            }
            rowIndex++;
        }
        colIndex++;
    }

    // Perform multiplication within the inner rows
    for (int row = 1; row < grid.size(); row++) {
        for (int col = 1; col < grid[row].size(); col++) {
            int value = grid[row][0] * grid[0][col];
            grid[row][col] = value;
        }
    }

    // Show the final 12 times table
    printTable(grid);

    return 0;
}

void printTable(vector<vector<int>> table) {
    cout << table[0].size() - 1 << " Times Table " << endl;
    for (int row = 0; row < table.size(); row++) {
        for (int col = 0; col < table[row].size(); col++) {
            cout << setw(5) << table[row][col] << flush;
        }
        cout << endl;
    }
}