#include <stdbool.h>

#ifndef _STRQ
#define _STRQ

struct strq {
    char string_data[50];    // strings stored in strq
    char *string_starts[25]; // pointers to the strings in strq
    int string_len;          // the number of strings currently stored in strq
};

#endif // _STRQ

// strq_init() returns an empty string queue.
// time:     O(1)
struct strq strq_init(void);

// strq_enqueue(strq, str) enqueues the string *str at the end of the string-
//   queue *strq, if there is still capacity in *strq, and returns false;
//   otherwise, the function returns true.
// effects:  might mutate *strq
// time:     O(n), where n is the length of *str
bool strq_enqueue(struct strq *strq, const char *str);

// strq_dequeue(strq, front) dequeues the front element of the string-queue
//   *strq and stores it in *front.
// requires: *strq must not be empty
// effects:  mutates *strq
//           mutates *front
// time:     O(n), where n is the maximum length of *strq
void strq_dequeue(struct strq *strq, char *front);

// strq_front(strq) returns the front element of the string-queue *strq.
// time:     O(1)
const char *strq_front(const struct strq *strq);

// strq_empty(strq) returns true if the string-queue *strq is empty, and false
//   otherwise.
// time:     O(1)
bool strq_empty(const struct strq *strq);

// strq_print(strq) prints the content of the string-queue *strq.
// effects:  writes to output
// time:     O(n), where n is the maximum length of *strq
void strq_print(const struct strq *strq);