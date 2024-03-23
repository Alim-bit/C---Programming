///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments >  Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Alim Dhuka
// login ID: adhuka
///////////////////////////////////////////////////////////////////////////////

#include "cs136-trace.h"

// Your additional includes go here.
#include "grid.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// See grid.h for documentation.
const int GRID_MAX_SIZE = 100;

// See grid.h for documentation.
struct grid grid_create(int rows, int cols) {
    // Your implementation goes here.
    assert(rows >= 0);
    assert(cols >= 0);
    struct grid new_grid = {cols, rows, rows * cols, {0}};
    // The .data = {0} initializes the entire array to zeros
    return new_grid;
}

// See grid.h for documentation.
int grid_rows(const struct grid *g) {
    // Your implementation goes here.
    return g->rows;
}

// See grid.h for documentation.
int grid_cols(const struct grid *g) {
    // Your implementation goes here.
    return g->cols;
}

// See grid.h for documentation.
bool grid_get(const struct grid *g, int row, int col, int *val) {
    // Your implementation goes here.
    assert(row >= 0);
    assert(col >= 0);
    assert(val);
    if (row < 0 || row >= g->rows || col < 0 || col >= g->cols) {
        return false; // Out of bounds
    }
    int index = row * g->cols + col;
    *val = g->data[index];
    return true;
}

// See grid.h for documentation.
bool grid_set(struct grid *g, int row, int col, int value) {
    // Your implementation goes here.
    assert(row >= 0);
    assert(col >= 0);
    assert(g);
    if (row < 0 || row >= g->rows || col < 0 || col >= g->cols) {
        return false; // Out of bounds
    }
    g->data[row * g->cols + col] = value;
    return true;
}

// See grid.h for documentation.
bool grid_resize(struct grid *g, int rows, int cols) {
    // Your implementation goes here.
    assert(rows >= 0);
    assert(cols >= 0);
    assert(g);
    if (rows * cols > GRID_MAX_SIZE) {
        return false; // Exceeds max size
    }
    struct grid temp = grid_create(rows, cols);
    int minRows = rows < g->rows ? rows : g->rows;
    int minCols = cols < g->cols ? cols : g->cols;
    for (int i = 0; i < minRows; ++i) {
        for (int j = 0; j < minCols; ++j) {
            temp.data[i * cols + j] = g->data[i * g->cols + j];
        }
    }
    
    *g = temp;
    return true;
}

// num_digits(number) returns the width of the number 
//   by calulating the number of digits 
//   and if the number is less than 0 
//   then it adds 1 to the width for the negative sign
// time:   O(log n),  n is number.
int num_digits(int number) {
    int digits = 0;
    if (number == 0) return 1; // Edge case for 0
    if (number < 0) digits += 1; // Add one for the negative sign
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

// See grid.h for documentation.
// Additional specifications:
// * all columns shall have the width of the widest number
// * there shall be exactly one additional space separating numbers
// Examples:
// [0 0]       <- column width: 1
// [ 0 42]     <- column width: 2
// [42  2]     <- column width: 2
// [-2  2]     <- column width: 2
// [ 2 -2]     <- column width: 2
// [  0 -42]   <- column width: 3
// [ 136 -136] <- column width: 4
// [-136  136] <- column width: 4
void grid_print(const struct grid *g) {
    // Your implementation goes here.
    assert(g);
    int max_width = INT_MIN;
    for (int i = 0; i < g->max_size; i++) { // Calculate the max_width
        int current_width = num_digits(g->data[i]);
        if (current_width > max_width) {
            max_width = current_width;
        }
    }

    // Print the grid, adjusting the calculation for `number`
    for (int i = 0; i < g->max_size; i++) {
        int col = i % g->cols; // Compute the current column
        int number = g->data[i]; 

        if (col == 0) {
            printf("["); // Print the opening bracket at the start of a new row
        }

        if (max_width == 1) { // if the max_width is 1
            if (col == g->cols - 1) {
                printf("%d", number);
            } else {
                printf("%d ", number);
            }
        } else {
            if (col == g->cols - 1) { // Last element in the row
                if (number < 0) {
                    for (int k = 0; k < max_width - num_digits(number); k++) {
                        printf(" ");
                    }
                } else {
                    for (int k = 0; k < max_width - 1; k++) {
                        printf(" ");
                    }
                }
                printf("%d", number);
            } else { // other element in the row
                int numSpaces = max_width - num_digits(number);
                for (int k = 0; k < numSpaces; k++) {
                    printf(" ");
                }
                printf("%d", number);
                if (col < g->cols - 1) {
                    printf(" ");
                }
            }
        }

        if (col == g->cols - 1) {
            printf("]\n"); // Print the closing bracket at the end of the row
        }
    }
}
