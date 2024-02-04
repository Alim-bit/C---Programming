#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cs136.h"

//printer(width, height, T_col, T_row, acci, accj) returns the printed pattern 
//using accumilative recursion
// requires: width, height, must be positive, T_col and T_row must be non-negative
// effects:  writes to the console
void printer(int width, int height, int T_col, int T_row, int acci, int accj) {
  if (height <= accj) {
    if (width <= acci) {
      if (height == T_row + 1 && width == T_col + 1) { // +1 since the position is starting from index 0
        printf("T");
        return printer((width + 1), height, T_col, T_row, acci, accj);
      } else {
        printf("*");
        return printer((width + 1), height, T_col, T_row, acci, accj);
      }
    } else {
    printf("\n");
    return printer(1, (height + 1), T_col, T_row, acci, accj);
  }
  }
}

// Consider defining global constants to make your code more readable.

// print_island(width, height, T_col, T_row) prints 'height' rows of 'width' stars ('*').
// At (T_col, T_row), the star is replaced with the letter "T"
// example:  print_island(5, 4, 2, 3)
//           *****
//           *****
//           *****
//           **T**
//
// requires: width, height, must be positive, T_col and T_row must be non-negative
// effects:  writes to the console
void print_island(int width, int height, int T_col, int T_row) {
  // your implementation goes here
  assert(width > 0 && height > 0 && T_col >= 0 && T_row >= 0);
  //Using Helper function for Accumulative Recursion 
  //so that we do not lose the orginal value while doing recursion
  printer(1, 1, T_col, T_row, width ,height); //starting from 1 since we need to go till width and height
  printf("The turtle is at (%d, %d).\n", T_col, T_row);
}

// turtle_run() should read in two positive integers corresponding to the
// width and height of an island. It should then continuously read integers
// from input corresponding to movement commands. The current state consists
// of a grid of 'height' rows and 'width' stars. A character "T" begins at position
// (0,0) and can be moved to a new row or column via movement commands. After each
// movement, the updated position is printed out.
// example:  turtle_run()  Input: 8 4 4 2 
//           T*******
//           ********
//           ********
//           ********
//           The turtle is at (0, 0).
//           *T******
//           ********
//           ********
//           ********
//           The turtle is at (1, 0).
//           ********
//           *T******
//           ********
//           ********
//           The turtle is at (1, 1).
// requires: input height, width must be positive
// effects:  writes to the console
void turtle_run(void) {
  // your implementation goes here
  int height = read_int();
  int width = read_int();
  int move_first = read_int();
  int move_second = read_int();
  int pos_r = 0;
  int pos_c = 0;
  assert(width > 0 && height > 0);
  assert(move_first == 1 || move_first == 2 || move_first == 3 || move_first == 4);
  assert(move_second == 1 || move_second == 2 || move_second == 3 || move_second == 4);
  print_island(height, width, pos_c, pos_r);
  //First Move
  if (move_first == 1) {
    //Up
    if(pos_r == 0) { // "wrap around" CASE
      print_island(height, width, pos_c, (height - 1));
      pos_r = height - 1;
    } else { // NORMAL MOVEMENT CASE
      print_island(height, width, pos_c, (pos_r - 1));
      pos_r = pos_r - 1;
    }
  } else if (move_first == 2) {
    //Down
    if(pos_r == height) { // "wrap around" CASE
      print_island(height, width, pos_c, 0);
      pos_r = 0;
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, pos_c, (pos_r + 1));
      pos_r = pos_r + 1;
    }
  } else if (move_first == 3) {
    //Left
    if(pos_c == 0) { // "wrap around" CASE
      print_island(height, width, (width - 1), pos_r);
      pos_c = width - 1;
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, (pos_c - 1), pos_r);
      pos_c = pos_c - 1;
    }
  } else if (move_first == 4) {
    //Right
    if(pos_c == width) { // "wrap around" CASE
      print_island(height, width, 0, pos_r);
      pos_c = 0;
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, (pos_c + 1), pos_r);
      pos_c = pos_c + 1;
    }
  }
  
  //Second Move
  if (move_second == 1) {
    //Up
    if(pos_r == 0) { // "wrap around" CASE
      pos_r = height - 1;
      print_island(height, width, pos_c, (height - 1));
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, pos_c, (pos_r - 1));
    }
  } else if (move_second == 2) {
    //Down
    if(pos_r == height) { // "wrap around" CASE
      pos_r = 0;
      print_island(height, width, pos_c, 0);
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, pos_c, (pos_r + 1));
    }
  } else if (move_second == 3) {
    //Left
    if(pos_c == 0) { // "wrap around" CASE
      pos_c = width - 1;
      print_island(height, width, (width - 1), pos_r);
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, (pos_c - 1), pos_r);
    }
  } else if (move_second == 4) {
    //Right
    if(pos_c == width) { // "wrap around" CASE
      pos_c = 0;
      print_island(height, width, 0, pos_r);
    } else { //NORMAL MOVEMENT CASE
      print_island(height, width, (pos_c + 1), pos_r);
    }
  }
  
}

int main(void) {
  turtle_run();
  return EXIT_SUCCESS;
}