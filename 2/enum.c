#include <stdio.h>

int main() {
  enum boolean { NO, YES };
  enum months { 
    JAN = 1, FEB, MAR, APR, MAY, JUN, 
    JUL, AUG, SEP, OCT, NOV, DEC
  };

  printf("NO %d, YES %d\n", NO, YES);
  printf(
    "JAN %d, FEB %d, MAR %d, APR %d, MAY %d, JUN %d, JUL %d, AUG %d, SEP %d, OCT %d, NOV %d, DEC %d\n", 
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
  );
}
