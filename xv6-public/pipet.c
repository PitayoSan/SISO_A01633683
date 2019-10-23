#include <stdio.h>
#include <stdlib.h>

int main() {
  fprintf(stderr, "Generasionando toooodos los numeros del 1 al 100, compa\n");
  for (int i = 2; i <= 100; i++) {
    printf("%d\n", i);
  }
  printf("%d\n",-1);
}