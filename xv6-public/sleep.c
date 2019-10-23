#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv) {
  if(argc != 2||atoi(argv[1])<=0){
    printf(2,"Error, senpai! Necesitas decirme cuanto tiempo dormir Z.z\n");
    exit();
  }
  sleep(atoi(argv[1])*100);
  exit();
}
