#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_lib.h"
#include "cs136-trace.h"

void public_tests(void) {
  int arr[6] = {1, 2, 1, 1, 2, 4};
  int arr_len = 6;
  assert(k_in_row(arr, arr_len, 3) == false);
  assert(max_diff(arr, arr_len) == 3);
  assert(max_freq(arr, arr_len) == 1);
  assert(max_val_idx(arr, arr_len) == 5);
}

int main(void) {
  public_tests();

  // more tests go here
  int arr1[1] = {100};
  assert(k_in_row(arr1,1,1) ==  true);
  int lst[8] = {2,232,433,23,22,24,78,22};
  assert(k_in_row(lst, 8, 2) == false);
  assert(max_val_idx(lst,8) == 2);
  assert(max_diff(lst,8) == 431);
  assert(max_freq(lst, 8) == 22);
  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}
