#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// sum_digits(n) returns the sum of all digits in n.
// requires: n must be non-negative
int sum_digits(int n) {
  // your implementation goes here
  assert(n >= 0);
  if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sum_digits(n / 10);
    }
  return -1;
}

int sum_alter(int n, int acc) { //acc as a pointer for which symbol to multiply by two and sum the digits
  if (n != 0) {
    if (acc % 2 == 0) {
      return (sum_digits ((n % 10) * 2)) + sum_alter(n / 10, (acc + 1));
    } else {
      return n % 10 + sum_alter(n / 10, (acc + 1)); 
    }
  } else {
  return 0;
  }
}

// sum_luhn(n) returns the Luhn sum of n.
// requires: n must be non-negative
int sum_luhn(int n) {
  // your implementation goes here
  assert(n >= 0);
  return sum_alter(n, 0);
}

// verify_card(number) returns true if the 8-digit card number is correct, and
//   false otherwise.
// requires: number must be exactly 8 digits long
bool verify_card(int number) {
  assert(10000000 <= number && number <= 99999999);
  // your implementation goes here
  // remember to only use the 7 leftmost digits to calculate the checksum
  if (number % 10 == (sum_digits (sum_luhn(number / 10)))) {
    return true;
  }
  return false;
}

void test_sum_digits(void) {
  assert(sum_digits(136) == 10);
  assert(sum_digits(10000001) == 2);
  assert(sum_digits(99999999) == 72);
  
  // your additional tests go here
  assert(sum_digits(17291627) ==35);
  assert(sum_digits(112311242) == 17);
  
  

}

void test_sum_luhn(void) {
  assert(sum_luhn(10000001) == 3);
  assert(sum_luhn(12345678) == 38);

  // your additional tests go here
  assert(sum_luhn(1729162) == 34);
  assert(sum_luhn(2112211) == 16);
}

void test_verify_card(void) {
  assert(verify_card(10000001) == false);
  assert(verify_card(10000002) == true);
  
  // your additional tests go here
  assert(verify_card(17291627) == true);
  assert(verify_card(21122118) == false);

}

int main(void) {
  // Remember that you can "comment out" function calls if you only want to
  //   run a single test suite.
  test_sum_digits();
  test_sum_luhn();
  test_verify_card();
  
  printf("All assertion-based tests passed!");
  //return EXIT_SUCCESS;
}