#include <stdio.h>

// Function prototypes
int validity_check(int scyscrapers[4][4], int row, int col, int num);
int fill_array(int scyscrapers[4][4], int row, int col);
void print_array(int scyscrapers[4][4]);

// Global variables for clues
int g_topclues[4] = {4, 3, 2, 1};
int g_bottomclues[4] = {1, 2, 2, 2};
int g_leftclues[4] = {4, 3, 2, 1};
int g_rightclues[4] = {1, 2, 2, 2};

int main() {
    // Initialize the array to zero
    int scyscrapers[4][4] = {0};

    // Fill the array
    if (fill_array(scyscrapers, 0, 0) == 0) {
        printf("Array populated successfully:\n");
    } else {
        printf("Failed to populate the array.\n");
    }

    // Print the result
    print_array(scyscrapers);

    return 0;
}

int validity_check(int scyscrapers[4][4], int row, int col, int num) {
    int i;

    // Check column for duplicates
    for (i = 0; i < 4; i++) {
        if (i != row && scyscrapers[i][col] == num) {
            return -1; // Number is not valid
        }
    }

    // Check row for duplicates
    for (i = 0; i < 4; i++) {
        if (i != col && scyscrapers[row][i] == num) {
            return -1; // Number is not valid
        }
    }

    // Check visibility from left
    int left_visible = countVisibleFromLeft(scyscrapers[row]);
    if (left_visible > g_leftclues[row]) {
        return -1; // More visible than allowed
    }

    // Check visibility from right
    int right_visible = countVisibleFromRight(scyscrapers[row]);
    if (right_visible > g_rightclues[row]) {
        return -1; // More visible than allowed
    }

    // Check visibility from top
    int top_visible = countVisibleFromTop(scyscrapers, col);
    if (top_visible > g_topclues[col]) {
        return -1; // More visible than allowed
    }

    // Check visibility from bottom
    int bottom_visible = countVisibleFromBottom(scyscrapers, col);
    if (bottom_visible > g_bottomclues[col]) {
        return -1; // More visible than allowed
    }

    return 0; // Number is valid if no duplicates and visibility checks pass
}

void print_array(int scyscrapers[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", scyscrapers[i][j]);
        }
        printf("\n");
    }
}

int fill_array(int scyscrapers[4][4], int row, int col) {
    if (row == 4) {
        return 0; // Successfully filled the array
    }

    if (col == 4) {
        return fill_array(scyscrapers, row + 1, 0); // Move to the next row
    }

    int num;
    for (num = 1; num <= 4; num++) {
        if (validity_check(scyscrapers, row, col, num) == 0) {
            scyscrapers[row][col] = num;
            if (fill_array(scyscrapers, row, col + 1) == 0) {
                return 0; // Success
            }
            scyscrapers[row][col] = 0; // Backtrack
        }
    }

    return -1; // Failure to place any number
}

int countVisibleFromLeft(int line[4]) {
    int maxSeen = 0;
    int visibleCount = 0;
    for (int i = 0; i < 4; i++) {
        if (line[i] > maxSeen) {
            visibleCount++;
            maxSeen = line[i];
        }
    }
    return visibleCount;
}

int countVisibleFromRight(int line[4]) {
    int maxSeen = 0;
    int visibleCount = 0;
    for (int i = 3; i >= 0; i--) {
        if (line[i] > maxSeen) {
            visibleCount++;
            maxSeen = line[i];
        }
    }
    return visibleCount;
}

int countVisibleFromTop(int grid[4][4], int col) {
    int maxSeen = 0;
    int visibleCount = 0;
    for (int row = 0; row < 4; row++) {
        if (grid[row][col] > maxSeen) {
            visibleCount++;
            maxSeen = grid[row][col];
        }
    }
    return visibleCount;
}

int countVisibleFromBottom(int grid[4][4], int col) {
    int maxSeen = 0;
    int visibleCount = 0;
    for (int row = 3; row >= 0; row--) {
        if (grid[row][col] > maxSeen) {
            visibleCount++;
            maxSeen = grid[row][col];
        }
    }
    return visibleCount;
}
