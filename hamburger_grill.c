#include <math.h> 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cs136.h"
#include "io-tests.h"

// === Global constants =======================================================

// represents a beef burger pattie [DO NOT CHANGE THIS VALUE]
const int PATTIE_BEEF =  1;
// represents a vegan burger pattie [DO NOT CHANGE THIS VALUE]
const int PATTIE_VEGAN = 2;

// === Global variables =======================================================
int bun = 0;
int beef_patties = 0;
int vegan_patties = 0;
int cheese = 0;
// === Helper functions =======================================================
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
// === Core functions =========================================================

// add_buns(crate) adds the content of crates to storage. A crate contains
//   eight buns.
// effect: might mutate global variable
//         might write to the console
void add_buns(int crate) {
  // use the following printf format string:
  //   "Error: invalid amount of crates in add_buns!\n"
  // your implementation goes here
  //printf("%d \n", crate);
  if (crate < 0) {
    printf("Error: invalid amount of crates in add_buns!\n");
  } else {
    bun += crate * 8;
  }
}

// add_patties(packs, pattie_type) adds the content of packs to storage. A
//   single pack contains twelve patties.
// effect: might mutate global variable
//         might write to the console
void add_patties(int packs, int pattie_type) {
  // use the following printf format string:
  //   "Error: invalid amount of packs in add_patties!\n"
  //   "Error: invalid pattie type in add_patties!\n"
  // your implementation goes here
  //printf("%d \n", packs);
  //printf("%d \n", pattie_type);
  if (packs < 0) {
    printf("Error: invalid amount of packs in add_patties!\n");
  } else if (pattie_type != PATTIE_BEEF && pattie_type != PATTIE_VEGAN) {
    printf("Error: invalid pattie type in add_patties!\n");
  } else {
    if (pattie_type == PATTIE_BEEF) {
      beef_patties += packs * 12;
    } else if (pattie_type == PATTIE_VEGAN){
      // Assuming PATTIE_VEGAN is 2
      // Handle adding vegan patties
      vegan_patties += packs *12;
    }
  }
}

// add_cheese(loaves) adds the loaves to storage. A single loaf can be cut into
//   fifty slices of cheese.
// effect: might mutate global variable
//         might write to the console
void add_cheese(int loaves) {
  // use the following printf format string:
  //   "Error: invalid amount of loaves in add_cheese!\n"
  // your implementation goes here
  //printf("%d \n", loaves);
  if (loaves < 0) {
    printf("Error: invalid amount of loaves in add_cheese!\n");
  } else {
    cheese += loaves * 50; // Assuming each loaf can be cut into fifty slices of cheese
  }
}

// prepare_order(burger_count, pattie_type, pattie_count) attempts to prepare
//   burger_count number of burgers. The type of patties is determined by
//   pattie_type. A single burger is made of pattie_count number of patties.
//   If burger_count is not a positive number, an error message is printed and
//     no burgers are made.
//   If pattie_type is neither PATTIE_BEEF nor PATTIE_VEGAN, an error message
//     is printed and no burgers are made.
//   If pattie_count is not between 1 and 3 (both inclusive), an error message
//      is printed and no burgers are made.
//   Each burger is made of
//     * one bun
//     * pattie_count number of patties (BEEF or VEGAN, depending on parameter
//       pattie_type)
//     * two slices of cheese for BEEF burger, zero slices for VEGAN burger
//   If one or more of the components are missing, warning messages are
//     printed. The order of messages is buns -> patties -> cheese.
//   If one or more of the components are missing, the maximum possible number
//     of burgers is made; if no components are missing, burger_count burgers
//     are made.
// effect: mutates global variable
//         writes to the console
void prepare_order(int burger_count, int pattie_type, int pattie_count) {
  // use the following printf string(s):
  //   "Error: invalid count of burgers in order!\n"
  //   "Error: invalid pattie type in order!\n"
  //   "Error: invalid number of patties in order!\n"
  //   "Warning: not enough buns to fulfill entire order!\n"
  //   "Warning: not enough patties (beef) to fulfill entire order!\n"
  //   "Warning: not enough patties (vegan) to fulfill entire order!\n"
  //   "Warning: not enough cheese to fulfill entire order!\n"
  //   "Info: %d burger(s) ready for pickup!\n"
  // your implementation goes here
  if (burger_count < 0) {
    printf("Error: invalid count of burgers in order!\n");
  } else if (pattie_type != PATTIE_BEEF && pattie_type != PATTIE_VEGAN) {
    printf("Error: invalid pattie type in order!\n");
  } else if (pattie_count > 3 || pattie_count < 1) {
    printf("Error: invalid number of patties in order!\n");
  } else {
    if (burger_count == 0 ) {
    int maxBurgers = 0;
    if (pattie_count == 1) {
      if (pattie_type == PATTIE_BEEF) {
        maxBurgers = min(bun, min(beef_patties, (cheese / 2))) / 2;
        bun = bun - maxBurgers;
        beef_patties = beef_patties - maxBurgers;
        cheese = cheese - (maxBurgers * 2);
      } else {
        maxBurgers = min(bun, vegan_patties) / 2;
        bun = bun - maxBurgers;
        vegan_patties = vegan_patties - maxBurgers;
      }
    } else if (pattie_count == 2) {
      if (pattie_type == PATTIE_BEEF) {
        maxBurgers = min(bun, min((beef_patties / 2), (cheese / 2)));
        bun = bun - maxBurgers;
        beef_patties = beef_patties - (maxBurgers * 2);
        cheese = cheese - (maxBurgers * 2);
      } else {
        maxBurgers = min(bun, (vegan_patties / 2));
        bun = bun - maxBurgers;
        vegan_patties = vegan_patties - (maxBurgers * 2);
      }
    } else if (pattie_count == 3) {
      if (pattie_type == PATTIE_BEEF) {
        maxBurgers = min(bun, min((beef_patties / 3), (cheese / 2)));
        bun = bun - maxBurgers;
        beef_patties = beef_patties - (maxBurgers * 3);
        cheese = cheese - (maxBurgers * 2);
      } else {
        maxBurgers = min(bun, (vegan_patties / 3));
        bun = bun - maxBurgers;
        vegan_patties = vegan_patties - (maxBurgers * 3);
      }
    }

    if (maxBurgers == 0) {
      printf("Warning: not enough ingredients to make any burgers!\n");
    } else {
      printf("Info: %d burger(s) ready for pickup!\n", maxBurgers);
      // Update inventory and prepare burgers
      }
  } else {
    prepare_order(burger_count - 1, pattie_type, pattie_count);
    }
  }
}


// print_inventory() prints the current inventory.
// effect: writes to the console
void print_inventory(void) {
  // modify the code below to make it work with your implementation
  printf("======== INVENTORY ========\n");
  printf("Buns:            %4d units\n", bun);
  printf("Patties (BEEF):  %4d units\n", beef_patties);
  printf("Patties (VEGAN): %4d units\n", vegan_patties);
  printf("Cheese:          %4d units\n", cheese);
}

// discard_inventory() discards the current inventory.
// effect: mutates global variable
//         writes to the console
void discard_inventory(void) {
  // use the following printf string(s):
  //   "Info: Stored food items discarded.\n"
  // your implementation goes here
  bun = 0;
  beef_patties = 0;
  vegan_patties = 0;
  cheese = 0;
  printf("Info: Stored food items discarded.\n");
}

int main(void) {
  run_hamburger();
  return EXIT_SUCCESS;
}