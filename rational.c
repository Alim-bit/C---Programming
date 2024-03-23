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

#include "cs136-trace.h"

// Your additional includes go here.
#include "rational.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
//#include <limits.h>
#include <stdbool.h>
// === HELPER FUNCTIONS =======================================================

// Your helper functions includes go here.

// gcd_cal(num1, num2) calculates the greatest common divisor of num1 and num2.
// time: O(log(min(num1, num2)))
int gcd_cal(int num1, int num2) {
    assert(num1 != 0 || num2 != 0);
    int temp;
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}
// === MODULE FUNCTIONS =======================================================

// See rational.h for documentation.
struct rational rational_init(int num, int denom) {
    // Your implementation goes here.
    assert(denom != 0);
    struct rational reduced_f = {num, denom};
    if (num < 0 && denom < 0) {
      reduced_f.num = abs(num);
      reduced_f.denom = abs(denom);
    } else if (num > 0 && denom < 0) {
        reduced_f.num = - num;
        reduced_f.denom = abs(denom);
    }
    reduced_f.num = reduced_f.num / gcd_cal(abs(num), abs(denom));
    reduced_f.denom = reduced_f.denom / gcd_cal(abs(num), abs(denom));

    return reduced_f;
}

// See rational.h for documentation.
bool rational_eq(struct rational a, struct rational b) {
    // Your implementation goes here.
    assert(a.denom != 0 && b.denom != 0);
    return (a.num == b.num) && (a.denom == b.denom);
}

// See rational.h for documentation.
void rational_print(const struct rational *r) {
    assert(r);
    if (r->num == 0 || r->denom == 1) {
        printf("%d\n", r->num);
    } else if (abs(r->num) < r->denom) { // r->denom cannot be non-positive
        printf("%d/%d\n", r->num, r->denom);
    } else { // r->num cannot be 0
        if (r->num > 0) {
            printf("%d %d/%d\n", r->num / r->denom, r->num % r->denom, r->denom);
        } else { // if (r->num < 0)
            printf("%d %d/%d\n", r->num / r->denom, abs(r->num) % r->denom, r->denom);
        }
    }
}

// See rational.h for documentation.
struct rational rational_add(struct rational a, struct rational b) {
    // Your implementation goes here.
    assert(a.denom != 0 && b.denom != 0);
    if (a.denom == b.denom) {
        return rational_init(a.num + b.num, b.denom);
    } else {
        return rational_init(((a.num * b.denom) + (b.num * a.denom)), (a.denom * b.denom));
    }
}

// See rational.h for documentation.
struct rational rational_mul(struct rational a, struct rational b) {
    // Your implementation goes here.
    assert(a.denom != 0 && b.denom != 0);
    return rational_init((a.num * b.num), (a.denom * b.denom));
}

// See rational.h for documentation.
struct rational rational_div(struct rational a, struct rational b) {
    // Your implementation goes here.
    assert(a.denom != 0 && b.denom != 0);
    return rational_init((a.num / a.denom),(b.num / b.denom));
}

// See rational.h for documentation.
struct rational rational_reciprocal(struct rational r) {
    // Your implementation goes here.
    assert(r.num != 0 && r.denom != 0);
    return rational_init(r.denom, r.num);
}