#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int infinito = 1;

void signalHandler(int signalNumber){
    printf("Signal received %d\n", signalNumber);
    sleep(2);
    infinito = 0;
}

int main() {
    int pid;
    signal(10, signalHandler);
    pid = fork();
    if(pid == 0) {
        printf("Soy el hijo del papa\n");
        while(infinito) {
            printf("into the void\n");
            sleep(1);
        }
        printf("Ya sali prros");
    } else {
        printf("Ich bin Daddy, yez\n");
        sleep(2);
        kill(pid, 10);
        for(;;);
    }
}
