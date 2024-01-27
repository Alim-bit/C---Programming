#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

int divide(int num, int denom) {
  // Remember: You may NOT use the multiplication, division, or module operator
  //   (*, /, or %). You MUST use a recursive approach!
  // your implementation goes here
  assert(denom != 0);
  if (num == 0) {
    return 0;
  } else if (num == denom) {
    return 1;
  } else if (num < denom) {
    return 1; // add one to round up to the neartest whole number
  } else {
    return 1 + divide((num - denom) ,denom);
  }
  return 0;
}

int assignment_compo(int assign_mrks, int assign_cnt, int style) {
  return divide(((assign_mrks + style) / (assign_cnt + 1)) * 20, 100); // +1 for Style
}

int exam_compo(int final, int midterm) {
  return divide(final * 50, 100) + divide(midterm * 25, 100);
}

int overrall(int assign_mrks, int assign_cnt, int style, int midterm, int final, int quizzes) {
                    return assignment_compo(assign_mrks, assign_cnt, style) + exam_compo(final, midterm) + divide(quizzes * 5, 100);
                  }
// cs136_passed(assign_mrks, assign_cnt, style, midterm, final, quizzes)
//   returns true if CS136 was passed, given the sum of all assignment marks
//   (assign_mrks), the number of submitted assignments (assign_cnt), the style
//   mark, midterm, final, and overall quiz mark (quizzes), and false
//   otherwise.
// requires: all parameters must be non-negative
//           assign_cnt must be smaller than 10
bool cs136_passed(int assign_mrks, int assign_cnt, int style,
                  int midterm, int final, int quizzes) {
  // your implementation goes here
  assert(assign_mrks >= 0 && assign_cnt >= 0 && assign_cnt < 10 && style >= 0 && midterm >= 0 && final >= 0 && quizzes >= 0);
  if (assign_cnt >= 6 && assignment_compo(assign_mrks, assign_cnt, style) >= 10 && exam_compo(final, midterm) > 37 && overrall(assign_mrks, assign_cnt, style,
                   midterm, final, quizzes) >= 50) {
                    return true;
                  }
  return false;
}

int main(void) {
  // public tests
  assert(cs136_passed(450, 9, 50, 50, 50, 50) == true);   // calculated mark: 50
  assert(cs136_passed(450, 9, 50, 50, 40, 100) == false); // calculated mark: 48
  
  // your additional tests go here
  assert(cs136_passed(300, 6, 47, 51, 49, 49) == true);
  assert(cs136_passed(300, 6, 47, 50, 47, 80) == false);
  
  printf("All assertion-based tests passed!");
  //return EXIT_SUCCESS;
}