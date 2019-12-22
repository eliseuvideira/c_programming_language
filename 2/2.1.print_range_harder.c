#include <stdio.h>

int main() {
  char c = (char)((unsigned char)~0 >> 1);
  short s = (short)((unsigned short)~0 >> 1);
  int i = (int)((unsigned int)~0 >> 1);
  long l = (long)((unsigned long)~0 >> 1);

  printf("min char %d\n", ~c);
  printf("max char %d\n", c);
  printf("min short int %d\n", ~s);
  printf("max short int %d\n", s);
  printf("min int %d\n", ~i);
  printf("max int %d\n", i);
  printf("min long int %ld\n", ~l);
  printf("max long int %ld\n", l);
  
  return 0; 
}
