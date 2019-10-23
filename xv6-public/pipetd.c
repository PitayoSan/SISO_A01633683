#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num = 0;
  int i = 0;
  scanf("%d\n",&num);
  fprintf(stderr, "%d\n", num);

  while(1){
    scanf("%d\n",&i);
    if(i == -1){
      break;
    }
    if(i % num != 0){
      printf("%d\n",i);
    }
  }
    printf("%d\n", -1);
}
