#include <stdio.h>

// Function prototypes
int validity_check(int scyscrapers[4][4], int row, int col, int num);
int fill_array(int scyscrapers[4][4], int row, int col);
void print_array(int scyscrapers[4][4]);

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
    int i = 0;

    // Check column for duplicates
    while (i < 4) {
        if (i != row) { // Skip the current row
            if (scyscrapers[i][col] == num) {
                return -1; // Number is not valid
            }
        }
        i++;
    }

    i = 0;
    // Check row for duplicates
    while (i < 4) {
        if (i != col) { // Skip the current column
            if (scyscrapers[row][i] == num) {
                return -1; // Number is not valid
            }
        }
        i++;
    }

    return 0; // Number is valid if no duplicates found
}

void print_array(int scyscrapers[4][4]) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            printf("%d ", scyscrapers[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int fill_array(int scyscrapers[4][4], int row, int col) {
    if (row == 4) {
        return 0; // Successfully filled the array
    }

    if (col == 4) {
        return fill_array(scyscrapers, row + 1, 0); // Move to the next row
    }

    int num = 1;
    while (num <= 4) {
        if (validity_check(scyscrapers, row, col, num) == 0) {
            scyscrapers[row][col] = num;
            if (fill_array(scyscrapers, row, col + 1) == 0) {
                return 0; // Success
            }
            scyscrapers[row][col] = 0; // Backtrack
        }

        num++;
    }

    return -1; // Failure to place any number
}

int countVisibleFromLeft(int line[4]) {
    int maxSeen = 0;
    int visibleCount = 0;
    int i = 0;

    while (i < 4) {
        if (line[i] > maxSeen) {
            visibleCount++;
            maxSeen = line[i];
        }
        i++;
    }

    return visibleCount;
}

int countVisibleFromRight(int line[4]) {
    int maxSeen = 0;
    int visibleCount = 0;
    int i = 3;

    while (i >= 0) {
        if (line[i] > maxSeen) {
            visibleCount++;
            maxSeen = line[i];
        }
        i--;
    }

    return visibleCount;
}

int countVisibleFromTop(int grid[4][4], int col) {
    int maxSeen = 0;
    int visibleCount = 0;
    int row = 0;

    while (row < 4) {
        if (grid[row][col] > maxSeen) {
            visibleCount++;
            maxSeen = grid[row][col];
        }
        row++;
    }

    return visibleCount;
}

int countVisibleFromBottom(int grid[4][4], int col) {
    int maxSeen = 0;
    int visibleCount = 0;
    int row = 3;

    while (row >= 0) {
        if (grid[row][col] > maxSeen) {
            visibleCount++;
            maxSeen = grid[row][col];
        }
        row--;
    }

    return visibleCount;
}

int g_topclues = {4, 3, 2, 1}
int	g_bottomclues = {1,2,2,2}
int	g_leftclues = {4, 3, 2, 1}
int	g_rightclues = {1,2,2,2}