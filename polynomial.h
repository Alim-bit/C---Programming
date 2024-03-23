#include "rational.h"

// The maximum degree of a polynomial
extern const int POLYNOMIAL_MAXDEG;

// A polynomial
struct polynomial {
    int deg; // degree of the polynomial; must not exceed POLYNOMIAL_MAXDEG
    struct rational data[100 + 1]; // + 1 for the 0th-degree, i.e., x^0
};

//  polynomial_init(p) returns a polynomial initialized to 0, i.e.,
//    0 + 0 x + 0 x^2 + 0 x^3 + ...
// time:     O(n), where n is POLYNOMIAL_MAXDEG
struct polynomial polynomial_init(void);

// polynomial_read() reads a new polynomial from input and returns it.
// example: > 2   2 3  7 2  1 2             =>   2/3 x^2 + 3 1/2 x + 1/2
//          > 4   2 3  0 1  7 2  1 2  0 1   =>   2/3 x^4 + 3 1/2 x^2 + 1/2 x
//            ^ degree of polynomial    
//                 ^ rational numbers as coefficients for each degree
// effects:  reads from input
// time:     O(n), where n is POLYNOMIAL_MAXDEG
struct polynomial polynomial_read(void);

// polynomial_print(p) prints the polynomial *p.
// effects:  produces output
// time:     O(n), where n is POLYNOMIAL_MAXDEG
void polynomial_print(const struct polynomial *p);

// polynomial_copy(dest, src) copies the polynomial *src into the polynomial
//   *dest.
// effects:  mutates *dest
// time:     O(n), where n is POLYNOMIAL_MAXDEG
void polynomial_copy(struct polynomial *dest, const struct polynomial *src);

// polynomial_add(dest, src) mutates the polynomial *dest so it contains the
//   sum of polynomials *dest and *src .
// effects:  mutates *dest
// time:     O(n), where n is POLYNOMIAL_MAXDEG
void polynomial_add(struct polynomial *dest, const struct polynomial *src);

// polynomial_mul(dest, src) mutates the polynomial *dest so it contains the
//   product of polynomials *dest and *src.
// requires: the sum of the degrees of *dest and *src must not exceed
//             POLYNOMIAL_MAXDEG
// effects:  mutates *dest
// time:     O(n^3), where n is POLYNOMIAL_MAXDEG
void polynomial_mul(struct polynomial *dest, const struct polynomial *src);
