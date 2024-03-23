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
#include "polynomial.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

const int POLYNOMIAL_MAXDEG = 100;

// --------- HEPLER FUNTION ---------
// max(a ,b) returns the max of a and b
// time : O(1)
int max(int a , int b) {
    return a > b ? a : b;
}

// See polynomial.h for documentation.
struct polynomial polynomial_init(void) {
    // Your implementation includes goes here.
    struct polynomial p = {POLYNOMIAL_MAXDEG, {rational_init(0,1)}};
    p.deg = 0; // Initialize the degree of the polynomial to 0.
    for (int i = 0; i <= POLYNOMIAL_MAXDEG; i++) {
        p.data[i] = rational_init(0, 1); // Initialize all coefficients to 0.
    }
    return p;
}

// See polynomial.h for documentation.
struct polynomial polynomial_read(void) {
    // Your implementation includes goes here.
    struct polynomial p = polynomial_init();
    int degree = INT_MIN;
    scanf("   %d", &degree);
    assert(degree <= POLYNOMIAL_MAXDEG);
    p.deg = degree;
    for (int i = 0; i <= p.deg; i++) {
        int num, denom;
        scanf("%d", &num);
        scanf("%d", &denom);
        assert(denom != 0);
        p.data[i] = rational_init(num,denom);
    }
    return p;
}

// See polynomial.h for documentation.
void polynomial_print(const struct polynomial *p) {
    // Your implementation includes goes here.
    assert(p);
    int isFirstTermPrinted = 0;

    for (int i = p->deg; i >= 0; i--) {
        if (isFirstTermPrinted) { // to print + alternatively
            printf(" + ");
        } else {
            isFirstTermPrinted = 1;
        }
        rational_print(&p->data[p->deg - i]); // printing the rational
        if (i >= 1) {  // printing the variable x 
            printf(" x");
        }
        if (i > 1) { // since x^1 is x
            printf("^%d", i);
        }
    }
    printf("\n");
}

// See polynomial.h for documentation.
void polynomial_add(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.
    assert(dest);
    assert(src);
    int align = 0; // Initialize alignment variable
    struct polynomial dest2 = *dest;
    struct polynomial src2 = *src;
    int max_deg = max(dest->deg , src->deg);
    for (int i = 0; i <= max_deg; ++i) {
        if (dest2.deg > src2.deg) {   // Aligning so , that we add the right coeffiecent
            dest->data[i] = dest->data[i];
            ++align;
            --dest2.deg;
        } else if (dest2.deg < src2.deg) {
            dest->data[i] = src->data[i];
            --align;
            --src2.deg;
        } else if (align > 0){
            dest->data[i] = rational_add(dest->data[i], src->data[i - align]);
        } else {
            dest->data[i] = rational_add(dest->data[i + align], src->data[i]);
        }
    }
}

// See polynomial.h for documentation.
void polynomial_copy(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.
    assert(dest);
    assert(src);
    assert(dest->deg <= POLYNOMIAL_MAXDEG && src->deg <= POLYNOMIAL_MAXDEG);
    int max_deg = max(dest->deg , src->deg);
    dest->deg = src->deg; // Copying the degree from src to dest
    for (int i = 0; i < max_deg; i++) {
        //Copying the numerator at i in data of src to the data of dest
        dest->data[i].num = src->data[i].num;
        //Copying the denomerator at i in data of src to the data of dest
        dest->data[i].denom = src->data[i].denom; 
    }
}

// See polynomial.h for documentation.
void polynomial_mul(struct polynomial *dest, const struct polynomial *src) {
    // Your implementation includes goes here.
    assert(dest);
    assert(src);
    struct polynomial result = polynomial_init();
    assert(dest->deg + src->deg <= POLYNOMIAL_MAXDEG);

    for (int i = 0; i <= dest->deg; i++) {
        for (int j = 0; j <= src->deg; j++) {
            if (i + j <= POLYNOMIAL_MAXDEG) {
                struct rational product = rational_init(
                    dest->data[i].num * src->data[j].num,
                    dest->data[i].denom * src->data[j].denom);

                // Add this product to the existing coefficient at degree i+j.
                result.data[i + j] = rational_init(
                    result.data[i + j].num * product.denom + product.num * result.data[i + j].denom,
                    result.data[i + j].denom * product.denom);
            }
        }
    }
    result.deg = dest->deg + src->deg;
    polynomial_copy(dest, &result);
}