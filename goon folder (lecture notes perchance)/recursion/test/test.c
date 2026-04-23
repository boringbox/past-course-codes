#include <stdio.h>

int factorial(int n) {
  printf("ENTER: %d\n", n);
  int ret;
  if (n == 0 || n == 1)
    ret = 1;
  else
    ret = n * factorial(n - 1);
  printf("EXIT: %d\n", n);
  return ret;
}

int main(void){
    int n = 4;
    int x = factorial(4);
    printf("%d", x);
    return 0;
}