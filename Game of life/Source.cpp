#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 15; //default size of the grid

// Function to initialize the grid with false values
void initGrid(bool grid[][SIZE]) {
    // Initialize the grid to false values (dead cells)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = false;
        }
    }

    // Prompt the user to enter live cell coordinates
    int row, col;
    cout << "Enter a live cell row and column (-1 -1 to finish): ";
    cin >> row >> col;

    // Read live cell coordinates until the user enters -1 -1
    while (row != -1 || col != -1) {
        // Validate the input (row and column within bounds)
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            grid[row][col] = true; // Mark the cell as alive
        }
        cout << "Enter a live cell row and column (-1 -1 to finish): ";
        cin >> row >> col;
    }
}

// Function to display the grid
void displayGrid(bool grid[][SIZE]) {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j]) {
                cout << "O "; // Display 'O' for live cells
            }
            else {
                cout << ". "; // Display '.' for dead cells
            }
        }
        cout << "\n";
    }
}

// Function to get the number of live neighbors
int getNumNeighbors(bool grid[][SIZE], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            // Check if the neighbor is within bounds and alive
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && (i != row || j != col) && grid[i][j]) {
                count++;
            }
        }
    }
    return count;
}

// Function to compute the next generation
void nextGeneration(bool grid[][SIZE]) {
    bool tempGrid[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int neighbors = getNumNeighbors(grid, i, j);
            // Apply the Game of Life rules
            if (grid[i][j]) { // Live cell
                if (neighbors < 2 || neighbors > 3) {
                    tempGrid[i][j] = false; // Dies from underpopulation or overcrowding
                }
                else {
                    tempGrid[i][j] = true; // Lives on
                }
            }
            else { // Dead cell
                if (neighbors == 3) {
                    tempGrid[i][j] = true; // Becomes alive from reproduction
                }
                else {
                    tempGrid[i][j] = false; // Remains dead
                }
            }
        }
    }

    // Copy the temporary grid to the original grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    bool grid[SIZE][SIZE];
    // Initialize the grid with dead cells
    initGrid(grid);

    // Main loop for the game
    char choice;
    do {
        displayGrid(grid); // Display the current generation
        cout << "Display next generation (y/n)? ";
        cin >> choice;
        if (choice == 'y') {
            nextGeneration(grid); // Compute the next generation
        }
    } while (choice == 'y');

    cout << "Press any key to continue...\n";
    cin.ignore();
    cin.get();

    return 0;
}