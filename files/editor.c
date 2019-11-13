#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    char *pattern = argv[1];
    char *newWord = argv[2];
    char *fileName = argv[3];

    char c;
    char word[100];
    int i = 0;
    int fd = open(fileName, O_RDONLY);
    int fd2 = open("tmp.txt", O_WRONLY | O_CREAT, 0666);
    while (read(fd, &c, 1)) {
        if(c != ' ') {
            word[i++] = c;
        } else {
            word[i] = '\0';
            i = 0;
            //printf("%s\n", word);
            if(strcmp(word, pattern) == 0) {
                write(fd2, newWord, strlen(newWord));
            } else {
                write(fd2, word, strlen(word));
            }
            write(fd2, " ", 1);
        }
    }
    word[i] = '\0';
    //printf("Última palabra %s\n", word);
    if(strcmp(word, pattern) == 0) {
        write(fd2, newWord, strlen(newWord));
    } else {
        write(fd2, word, strlen(word));
    }
    close(fd);
    close(fd2);
    unlink(fileName);
    link("tmp.txt", fileName);
    unlink("tmp.txt");
    return 0;
}