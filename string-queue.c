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

#include "string-queue.h"
#include "cs136-trace.h"

// Your additional includes go here.
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

const int STRQ_LEN = 50; // maximum number of character that can be stored

// See string-queue.h for documentation.
struct strq strq_init(void) {
    // Your implementation go here.
    struct strq sq;
    sq.string_len = 0;
    return sq;
} 

// See string-queue.h for documentation.
bool strq_empty(const struct strq *strq) {
    // Your implementation go here.
    assert(strq);
    return strq->string_len == 0;
}

// See string-queue.h for documentation.
const char *strq_front(const struct strq *strq) {
    // Your implementation go here.
    assert(strq);
    if (strq_empty(strq)) {
        return NULL; // Or handle as per requirement
    }
    return strq->string_starts[0];
}

// See string-queue.h for documentation.
bool strq_enqueue(struct strq *strq, const char *str) {
    // Your implementation go here.
    assert(strq);
    assert(str);
    int len = strlen(str);
    if (strq->string_len >= 25 || STRQ_LEN - strlen(strq->string_data) - 1 < len + 1) { // Adjust space check for '\0'
        return true;
    }
    // Copy the string to the next free position
    if (strq->string_len > 0) { // Adjust for existing strings
        strq->string_starts[strq->string_len] = strq->string_data + strlen(strq->string_data) + 1;
    } else {
        strq->string_starts[0] = strq->string_data;
    }
    strcpy(strq->string_starts[strq->string_len], str);
    strq->string_len++;
    // Null-terminate the current end of string_data
    strq->string_data[strlen(strq->string_data) + len + 1] = '\0';
    return false;
}

// See string-queue.h for documentation.
void strq_dequeue(struct strq *strq, char *top) {
    // Your implementation go here.
    assert(strq);
    assert(top);
    if (strq_empty(strq)) {
        return; // Handle as per requirement
    }

    // Copy the dequeued string to top.
    strcpy(top, strq->string_starts[0]);
    int len = strlen(top) + 1; // Length to shift, including '\0'
    
    // Calculate the start and the end of the string data to shift.
    char *start_to_shift = strq->string_starts[0] + len;
    char *end_of_data = strq->string_starts[strq->string_len - 1];
    end_of_data += strlen(end_of_data) + 1; // Move to the end of the last string, plus null terminator.

    // Shift the data manually and update string_starts pointers.
    char *current = strq->string_starts[0];
    while (start_to_shift < end_of_data) {
        *current = *start_to_shift;
        current++;
        start_to_shift++;
    }

    // Manually set the rest of the string_data to '\0'.
    while (current < end_of_data) {
        *current = '\0';
        current++;
    }
    
    // Update the string_starts pointers to new positions.
    for (int i = 0; i < strq->string_len - 1; i++) {
        strq->string_starts[i] = strq->string_starts[i + 1] - len;
    }

    // Decrement the number of strings.
    strq->string_len--;
}

// See string-queue.h for documentation.
void strq_print(const struct strq *strq) {
    // The function prints every sting currently stored in *strq, front to
    //   back, separated by ", ", and bookended with "[" and "]".
    //   An empty string queue would be printed as "[]".
    // Your implementation go here.
    assert(strq);
    printf("[");
    for (int i = 0; i < strq->string_len; ++i) {
        // Ensure the string_starts[i] is within bounds of string_data
        if (strq->string_starts[i] >= strq->string_data && 
            strq->string_starts[i] < strq->string_data + STRQ_LEN) {
            printf("%s", strq->string_starts[i]);
        } else {
            printf("Invalid string pointer");
        }
        if (i < strq->string_len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}