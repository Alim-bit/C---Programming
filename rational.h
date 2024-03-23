#include <stdbool.h>

#ifndef _RATIONAL
#define _RATIONAL

// A rational number
struct rational {
  int num;   // the numerator
  int denom; // the denominator
};

#endif // _RATIONAL

// A rational representing 0.
extern const struct rational RTNL_ZERO;

// rational_init(num, denom) returns the reduced rational number num/denom.
// requires: denom must not be 0
// time:     O(n), where n is max(num, denom)
struct rational rational_init(int num, int denom);

// rational_eq(a, b) returns true if a equals b, and false otherwise.
// time:     O(1)
bool rational_eq(struct rational a, struct rational b);

// rational_add(a, b) returns the reduced sum of a and b.
// example:  rtnl_add({1,2}, {1,2}) => {1,1}
//           rtnl_add({2,3}, {4,3}) => {2,1}
// time:     O(n), where n is max(num, denom)
struct rational rational_add(struct rational a, struct rational b);

// rational_mul(a, b) returns the reduced product of a and b.
// example:  rtnl_mul({1,2}, {1,2}) => {1,4}
//           rtnl_mul({3,2}, {4,5}) => {6,5}
// time:     O(n), where n is max(num, denom)
struct rational rational_mul(struct rational a, struct rational b);

// rational_div(a, b) returns the reduced quotient of a over b.
// requires: b must not represent zero
// example:  rtnl_div({1,2}, {1,2}) => {1,1}
//           rtnl_div({3,2}, {5,4}) => {6,5}
// time:     O(n), where n is max(num, denom)
struct rational rational_div(struct rational a, struct rational b);

// rational_reciprocal(r) returns the reciprocal of rational r.
// requires: r must not represent zero
// example:  rtnl_reciprocal({3,8}) => {8,3}
// time:     O(n), where n is max(num, denom)
struct rational rational_reciprocal(struct rational r);

// rational_print(r) prints the rational *r as a fraction.
// effects: writes to output
// time:     O(1)
void rational_print(const struct rational *r);