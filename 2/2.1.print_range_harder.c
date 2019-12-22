#include <stdio.h>

int main() {
  char c = (char)((unsigned char)~0 >> 1);
  short s = (short)((unsigned short)~0 >> 1);
  int i = (int)((unsigned int)~0 >> 1);
  long l = (long)((unsigned long)~0 >> 1);

  printf("%d\n", ~c);
  printf("%d\n", c);
  printf("%d\n", ~s);
  printf("%d\n", s);
  printf("%d\n", ~i);
  printf("%d\n", i);
  printf("%ld\n", ~l);
  printf("%ld\n", l);
  
  return 0; 
}
