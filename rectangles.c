#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cs136.h"

//printer(i, j, acci, accj)  returns the printed pattern 
//using accumilative recursion
void printer(int i, int j, int acci, int accj) {
  if (j != 0) {
    if (i != 0) {
      printf("*");
      printer(i - 1, j, acci, accj);
    } else {
      printf("\n");
      printer(acci, j - 1, acci, accj);
    }
  }
}
//print_rectangles(void) returns the pattern of "*" with the first input 
//as the number of rows and second number as colomns
void print_rectangles(void) {
// Your implementation goes here
int i = read_int();
int j = read_int();
return printer(i, j, i, j);
}

int main(void) {
  print_rectangles();
}