#include <stdio.h>
#include "cs136-trace.h"
#include "polynomial.h"

// The following commands are available:
// READ <deg:int> [<num:int><denom:int>]
//      Initializes the current polynomial with values from input. The first
//      value deg represents the maximum degree of the polynomial; it must be
//      a non-negative number. This is followed by (deg+1) pairs of numbers
//      (numerator / denominator) which represent the coefficients for each
//      term, starting with the highest degree.
// ADD <deg:int> [<num:int><denom:int>]
//      Adds a polynomial from input to the current polynomial. The format is
//      the same as for the READ command (see above).
// MUL <deg:int> [<num:int><denom:int>]
//      Multiplies the current polynomial with one from input. The format is
//      the same as for the READ command (see above).
int main(void) {
    struct polynomial poly = polynomial_init();

    const int CMD_READ = lookup_symbol("READ");
    const int CMD_ADD = lookup_symbol("ADD");
    const int CMD_MUL = lookup_symbol("MUL");

    int cmd = INVALID_SYMBOL;

    while ((cmd = read_symbol()) != INVALID_SYMBOL) {
        print_symbol(cmd);
        printf(": ");
        if (CMD_READ == cmd) {
            poly = polynomial_read();
        } else if (CMD_ADD == cmd) {
            struct polynomial tmp = polynomial_read();
            polynomial_add(&poly, &tmp);
        } else if (CMD_MUL == cmd) {
            struct polynomial tmp = polynomial_read();
            polynomial_mul(&poly, &tmp);
        } else {
            printf("ERROR: unknown command\n");
            break;
        }
        polynomial_print(&poly);
    }
}
