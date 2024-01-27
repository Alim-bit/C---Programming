#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int check_hailstone(int h) {
  return (h % 2 == 0) ? h / 2 : 3 * h + 1;
}
// nth_hailstone(int x, int n) returns the n-th Hailstone number of a given
//   number x.
// requires: x and n must both be non-negative
int nth_hailstone(int x, int n) {
  // your implementation goes here
  if (n != 0) {
    return nth_hailstone(check_hailstone(x), n - 1);
  } else {
    return x;
  }
  return 0;
}

int main(void) {
  // public tests
  assert(nth_hailstone(5, 2) == 8);   //              5 ->
                                      // 5 * 3 + 1 = 16 ->
                                      // 16 / 2 =     8

  assert(nth_hailstone(11, 5) == 13); //              11 ->
                                      // 11 * 3 + 1 = 34 ->
                                      // 34 / 2 =     17 ->
                                      // 17 * 3 + 1 = 52 ->
                                      // 52 / 2 =     26 ->
                                      // 26 / 2 =     13

  // your additional tests go here
  assert(nth_hailstone(6, 3) == 5);
  assert(nth_hailstone(100, 5) == 19);
  assert(nth_hailstone(-5, 2) == -7);
  assert(nth_hailstone(-7, 3) == -5);
  printf("All assertion-based tests passed!");
  //return EXIT_SUCCESS;
}