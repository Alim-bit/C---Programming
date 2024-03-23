#include <assert.h>
#include <stdio.h>
#include "rational.h"
#include "cs136-trace.h"

// The following commands are available:
// ASSIGN <num:int> <denom:int>
//        Initializes the current rational with num (numerator) and denom
//        (denominator).
// ADD <num:int> <denom:int>
//        Adds the rational given by num (numerator) and denom (denominator) to
//        the current rational.
// MUL <num:int> <denom:int>
//        Multiplies the current rational with another rational given by num
//        (numerator) and denom (denominator).
// DIV <num:int> <denom:int>
//        Devides the current rational with another rational given by num
//        (numerator) and denom (denominator).
// REC    Takes the reciprocal of the current rational.
int main(void) {
    const int CMD_ASSIGN = lookup_symbol("ASSIGN");
    const int CMD_ADD = lookup_symbol("ADD");
    const int CMD_MUL = lookup_symbol("MUL");
    const int CMD_DIV = lookup_symbol("DIV");
    const int CMD_REC = lookup_symbol("REC");

    int cmd = INVALID_SYMBOL;
    struct rational rtnl = rational_init(0, 1);

    while((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (CMD_REC == cmd) {
            rtnl = rational_reciprocal(rtnl);
        } else {
            int num = 0;
            int denom = 0;
            if (scanf("%d %d", &num, &denom) != 2) {
                break;
            }
            if (CMD_ASSIGN == cmd) {
                rtnl = rational_init(num, denom);
            } else if (CMD_ADD == cmd) {
                rtnl = rational_add(rtnl, rational_init(num, denom));
            } else if (CMD_MUL == cmd) {
                rtnl = rational_mul(rtnl, rational_init(num, denom));
            } else if (CMD_DIV == cmd) {
                rtnl = rational_div(rtnl, rational_init(num, denom));
            }
        }
        print_symbol(cmd);
        printf(": ");
        rational_print(&rtnl);
    }
}
