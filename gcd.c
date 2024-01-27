#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// gcd(int m, int n) returns the greatest common denominator of m and n.
// requires: m, n must be positive
int gcd(int m, int n) {
  // your implementation goes here
  assert(m >= 0);
  assert(n >= 0);
  if (n == 0) {
        return m;
  } else {
    return gcd(n, m % n);
  }
  return 0;
}

int main(void) {
  // public tests
  assert(gcd(18, 27) == 9);

  // your additional tests go here
  assert(gcd(2, 3) == 1);
  assert(gcd(25, 10) == 5);
  assert(gcd(23, 25) == 1);
  printf("All assertion-based tests passed!");
  //return EXIT_SUCCESS;
}