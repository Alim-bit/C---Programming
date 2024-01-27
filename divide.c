#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// divide(num, denom) returns the quotient of numerator num and denominator
//   denom.
// requires: denom cannot be 0
int divide(int num, int denom) {
  // Remember: You may NOT use the multiplication, division, or module operator
  //   (*, /, or %). You MUST use a recursive approach!
  // your implementation goes here
  if (num == 0) {
    return 0;
  } else if (num < 0 && denom < 0) {  //if numerator and denominator are negetive
    return divide(abs(num), abs(denom)); 
  } else if (num < 0) { //if numerator is negative
    return - divide(abs(num) , denom);
  } else if (denom < 0) { //if denominator is negative
    return - divide(num , abs(denom));
  } else if (num == denom) {
    return 1;
  } else if (num < denom) {
    return 0;
  } else {
    return 1 + divide((num - denom) ,denom);
  }
  return 0;
}

int main(void) {
  // public tests
  printf("Begin");
  printf("%d \n",(divide(10, 5) == 2));
  assert(divide(1205, 2) == 602);

  // your additional tests go here
  assert(divide(4, 2) == 2);
  assert(divide(4, 4) == 1);
  assert(divide(-12, 3) == -4);
  assert(divide(15, -3) == -5);
  assert(divide(-18, -9) == 2);
  printf("All assertion-based tests passed!");
 // return
}