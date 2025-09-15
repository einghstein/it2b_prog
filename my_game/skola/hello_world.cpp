#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Function to check if an array of 9 values has all digits 1–9 without duplicates
bool isValidSet(int arr[SIZE]) {
    bool seen[SIZE + 1] = {false}; // index 1–9
    for (int i = 0; i < SIZE; i++) {
        int num = arr[i];
        if (num < 1 || num > 9 || seen[num]) {
            return false;
        }
        seen[num] = true;
    }
    return true;
}

bool isValidSudoku(int grid[SIZE][SIZE]) {
    int arr[SIZE];

    // Check rows
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) arr[j] = grid[i][j];
        if (!isValidSet(arr)) return false;
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) arr[i] = grid[i][j];
        if (!isValidSet(arr)) return false;
    }

    // Check 3×3 subgrids
    for (int row = 0; row < SIZE; row += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            int idx = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[idx++] = grid[row + i][col + j];
                }
            }
            if (!isValidSet(arr)) return false;
        }
    }

    return true;
}

void sudoku(){
	bool run = true;
    int grid[SIZE][SIZE];

    // Seed the random number generator
    srand(time(NULL));
	while (run){
		
	    // Fill the grid with random numbers between 1 and 9
	    for (int i = 0; i < SIZE; i++) {
	        for (int j = 0; j < SIZE; j++) {
	            grid[i][j] = (rand() % 9) + 1;
	        }
	    }
	
	    // Print the grid
	    for (int i = 0; i < SIZE; i++) {
	        for (int j = 0; j < SIZE; j++) {
	            printf("%d ", grid[i][j]);
	        }
	        printf("\n");
	    }
	    
	        // Check validity
	    if (isValidSudoku(grid)) {
	        printf("This is a valid Sudoku!\n");
	        run = false;
	    } 
	}
	// Print the grid
	    for (int i = 0; i < SIZE; i++) {
	        for (int j = 0; j < SIZE; j++) {
	            printf("%d ", grid[i][j]);
	        }
	        printf("\n");
	    }
	    
}



void letadlo (){
    int hodiny;
    int minuty;
    int S;
    int V;
    int plus;
    bool overflow = false;

    printf("hodiny: ");
    scanf("%d", &hodiny);

    printf("minuty: ");
    scanf("%d", &minuty);

    printf("S: ");
    scanf("%d", &S);

    printf("V: ");
    scanf("%d", &V);

    plus = S/V;
    hodiny += plus;

    double result = (double)S / V;   // 3.5
    double frac   = result - (int)result; // 3.5 - 3 = 0.5

    minuty += frac * 60;
    if (minuty >= 60){
    	minuty -= 60;
    	hodiny += 1;
	}
    if (hodiny >= 24){
        hodiny -= 24;
        overflow = true;
    }
    printf("%d:%d, o %d dni pozdeji", hodiny, minuty, overflow);
}

int main () {
    //std::cout << "Hello world";
    //letadlo();
    sudoku();
	return 0;
}