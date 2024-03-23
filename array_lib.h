#include <stdbool.h>

// k_in_row(arr, arr_len, k) returns true if arr[] contains at least k equal
//   values in a row, and false otherwise.
// time: O(n)
bool k_in_row(const int arr[], int arr_len, int k);

// max_freq(arr, arr_len) returns the most frequent element in arr[]. If more
//   than one element has the same frequency, max_freq selects one
//   arbitrarily.
// effects: arr[] might be mutated
// time:    O(n log n)
int max_freq(int arr[], int arr_len);

// max_diff(arr, arr_len) returns the maximum difference between any two
//    elements in arr[].
// time: O(n)
int max_diff(const int arr[], int arr_len);

// max_val_idx(arr, arr_len) returns the index of the maximum value in arr[].
//   If more than one elements have the same maximum value, the index of the
//   first one is returned.
// time: O(n)
int max_val_idx(const int arr[], int arr_len);