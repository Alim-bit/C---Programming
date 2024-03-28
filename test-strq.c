#include <assert.h>
#include <stdio.h>
#include "string-queue.h"
#include "cs136-trace.h"

// The following commands are available:
// ENQ <element:string>
//     Enqueues the string element at the end of the string-queue. The maximum
//     length of element is 20.
// DEQ
//     Dequeues and prints the first element of the string-queue.
// FRONT
//     Retrieves and prints the first element of the string-queue.
// EMPTY
//     Prints whether the string-queue is empty.
int main(void) {
    const int CMD_ENQ = lookup_symbol("ENQ");
    const int CMD_DEQ = lookup_symbol("DEQ");
    const int CMD_FRONT = lookup_symbol("FRONT");
    const int CMD_EMPTY = lookup_symbol("EMPTY");

    int cmd = INVALID_SYMBOL;

    struct strq my_strq = strq_init();

    while((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (cmd == CMD_ENQ) {
            char enq_str[21] = {'\0'};
            assert(scanf("%20s", enq_str) == 1);
            if (!strq_enqueue(&my_strq, enq_str)) {
                printf("Enqueued %s : ", enq_str);
                strq_print(&my_strq);
            } else {
                printf("Warning: enqueue failed\n");
            }
        } else if (cmd == CMD_DEQ) {
            char deq_str[21] = {'\0'};
            strq_dequeue(&my_strq, deq_str);
            printf("Dequeued %s : ", deq_str);
            strq_print(&my_strq);
        } else if (cmd == CMD_FRONT) {
            printf("Front: %s\n", strq_front(&my_strq));
        } else if (cmd == CMD_EMPTY) {
            printf("Info: string-queue is%sempty\n", strq_empty(&my_strq) ? " " : " not ");
        } else {
            printf("ERROR: unknown command\n");
            break;
        }
    }
}