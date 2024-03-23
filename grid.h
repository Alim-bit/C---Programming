#include <stdbool.h>

#ifndef _GRID
#define _GRID

// A grid
struct grid {
  int cols;      // number of columns in the grid
  int rows;      // number of rows in the grid
  int max_size;  // maximum number of elements in the grid (cols * rows <= max_size)
  int data[100]; // the data
};

#endif // _GRID

extern const int GRID_MAX_SIZE;

// grid_create(rows, cols) returns a new grid with rows rows and cols columns.
// requires: rows and cols must be positive
//           rows * cols must not be larger than GRID_MAX_SIZE
// time:     O(1)
struct grid grid_create(int rows, int cols);

// grid_rows(g) returns the number of rows in grid g.
// time:     O(1)
int grid_rows(const struct grid *g);

// grid_cols(g) returns the number of columns in grid g.
// time:     O(1)
int grid_cols(const struct grid *g);

// grid_get(g, row, col, val) stores the element at (row, col) of grid g in
//   *val. The function returns true if it was successful, and false otherwise.
//   (The function might fail if row or col are outside the grid.)
// effects:  might mutate *val
// time:     O(1)
bool grid_get(const struct grid *g, int row, int col, int *val);

// grid_set(g, row, col, val) sets the element at (row, col) in grid g to
//   value val. The function returns true if it was successful, and false
//   otherwise. (The function might fail if row or col are outside the grid.)
// effects:  might mutate *g
// time:     O(1)
bool grid_set(struct grid *g, int row, int col, int value);

// grid_resize(g, rows, cols) resizes grid g to have rows rows and col columns.
//   If a dimension shrinks, elements are discarded; if a dimension grows, new
//   elements are set to 0. Already existing elements stay at their current
//   location. The function returns true if it was successful, and false
//   otherwise. (The function might fail if rows * cols exceeds GRID_MAX_SIZE.)
// example:  [1 2 3 4]   resize(3,2)    [1 2]   resize(1,6)    
//           [5 6 7 8]  =============>  [5 6]  =============>  [1 2 0 0 0 0]
//                                     [0 0]
// effects:  might mutate *g
// time:     O(n), where n is GRID_MAX_SIZE
bool grid_resize(struct grid *g, int rows, int cols);

// grid_print(g) prints the grid g.
// effects:  writes to output
// time:     O(n), where n is GRID_MAX_SIZE
void grid_print(const struct grid *g);