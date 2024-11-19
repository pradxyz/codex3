#include <iostream>
using namespace std;
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0)
                cout << ". ";
            else
                cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isValid(int grid[9][9], int row, int col, int num) {
       for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) return false;
    }

   
    for (int x = 0; x < 9; x++) {
        if (grid[x][col] == num) return false;
    }

       int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) return false;
        }
    }

    return true;
}
bool solveSudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) { 
                for (int num = 1; num <= 9; num++) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num; 

                        if (solveSudoku(grid)) {
                            return true; 
                        }

                        grid[row][col] = 0; 
                    }
                }
                return false;             }
        }
    }
    return true; 
}

int main() {
    int grid[9][9];

   
    cout << "Enter the Sudoku grid row by row (use 0 for empty cells):\n";
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> grid[row][col];
            if (grid[row][col] < 0 || grid[row][col] > 9) {
                cout << "Invalid input! Please enter numbers between 0 and 9.\n";
                return 1;
            }
        }
    }

    cout << "\nUnsolved Sudoku:\n";
    printGrid(grid);

       if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
