#include <stdio.h>
#include <math.h>

int main() {
  struct point {
    int x;
    int y;
  };
  double dist, sqrt(double);

  struct point point1 = { 320, 200 };
  struct point point2 = { 120, 400 };

  dist = sqrt((double)point1.x * point1.x + (double)point2.y * point2.y);

  printf("%19.8f", dist);

  struct rectangle {
    struct point pt1;
    struct point pt2;
  };

  struct rectangle screen;

  return 0;
}
