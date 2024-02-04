#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cs136.h"
//recursive_mean(sum, count) returns the mean using the sum of the input using an recursive call 
//and counts the number of integer inputs and return the mean.
int recursive_mean(int sum, int count) {
  int num = read_int();
  assert(sum >= 0 && count >= 0);
  if (num != READ_INT_FAIL) {
    int mean = recursive_mean(sum + num, count + 1); // Recursively call the function with updated sum and count
    return mean;
  } else {
    int mean = sum / count;
    printf("The mean is %d.\n", mean);
    return mean;
  }
}
// print_mean() reads in all numbers from the console and prints out their
//   mean.
// effects: reads from the console
//          writes to the console
void print_mean(void) {
  // use the following printf format string:
  //   "The mean is %d.\n"
  // your implementation goes here
  recursive_mean(0, 0); // Start with sum = 0 and count = 0
}

int main(void) {
  print_mean();
  return EXIT_SUCCESS;
}