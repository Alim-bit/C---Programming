///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments >  Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Alim Dhuka
// login ID: adhuka
///////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include "array_lib.h"
#include <stdlib.h>
#include "merge_sort.h"
#include <limits.h>

// See array_lib.h for documentation.
bool k_in_row(const int arr[], int arr_len, int k) {
  assert(arr);
  assert(arr_len > 0);
  assert(k > 0);
  
  int count = 1; 
  if ( k == 1 && arr_len == 1) { 
    return true; 
  }

  for (int i = 1; i < arr_len; i++) {
    if (arr[i] == arr[i - 1]) {
      ++count;
      if (count == k) {
        return true;
      }
    } else {
      count = 1; // Reset count if the current element is different from the previous one
    }
  }
  return false; // Return false if no sequence of k identical elements is found
}

// See array_lib.h for documentation.
int max_freq(int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);

  // Sort the array, O(n log n) time complexity
  merge_sort(arr, arr_len);

  int current_freq = 1;
  int max_freq = 1;
  int max_freq_element = arr[0];

  // After sorting, identical elements are adjacent. 
  // We can find the most frequent by a single pass, O(n) time complexity.
  for (int i = 1; i < arr_len; i++) {
    if (arr[i] == arr[i - 1]) {
      current_freq++;
    } else {
      if (current_freq > max_freq) {
        max_freq = current_freq;
        max_freq_element = arr[i - 1];
      }
      current_freq = 1; // Reset for the next element
    }
  }

  // Check last element sequence
  if (current_freq > max_freq) {
    max_freq_element = arr[arr_len - 1];
  }

  return max_freq_element;
}


// See arrayfun.h for documentation.
int max_diff(const int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);
  
  int min_val = INT_MAX;
  int max_val = INT_MIN;
  
  for (int i = 0; i < arr_len; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  
  return max_val - min_val;
}

// See array_lib.h for documentation.
int max_val_idx(const int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);
  
  int max_idx = 0;
  //int max_val = arr[0];
  for (int i = 1; i < arr_len; i++) {
    if (arr[i] > arr[max_idx]) {
      //max_val = arr[i];
      max_idx = i;
    }
  }
  return max_idx;
}

