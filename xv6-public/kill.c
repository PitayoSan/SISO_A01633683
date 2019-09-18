#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    exit();
  }
  for(i=1; i<argc; i++)
  if(atoi(argv[i]) == 1) {
    printf(1, "Orale, P*to! Con mi gfe no te metas OwX\n");
  } else {
    kill(atoi(argv[i]));
  }
  exit();
}
