#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct full_student{
    char name[20];
    char lastname[20];
    int prisonerId;
    char semester;
} Student;

void writeStudent(int agrc, char **argv) {
    char * fileName = argv[1];
    int fd = open(fileName, O_WRONLY | O_CREAT, 0666);
    for(int i =0; i < 5; i++) {
        Student myStudent;
        sprintf(myStudent.name, "juanito_%d", i);
        sprintf(myStudent.lastname, "pérez_%d", i);
        myStudent.prisonerId = (i+1)*10;
        myStudent.semester = (i+1);
        write(fd,&myStudent, sizeof(Student));
    }
    close(fd);
}

void readStudent(int argc, char **argv) {
    char * fileName = argv[1];
    int fd = open(fileName, O_RDONLY);
    Student myStudent;
    int element  = atoi(argv[2]);
    lseek(fd, element*sizeof(Student), SEEK_SET);
    read(fd, &myStudent, sizeof(Student));
    close(fd);
    printf("Student name: %s %s\n", myStudent.name, myStudent.lastname);
    printf("Id: %d, semester: %d\n", myStudent.prisonerId, myStudent.semester);
}

int main(int argc, char **argv){
    char * fileName = argv[1];
    char * lastName = argv[2];
    char * newLastName = argv[3];
    int fd = open(fileName, O_RDONLY);
    int posElement = -1;
    for(int i = 0; i < 5; i++) {
        Student myStudent;
        read(fd, &myStudent, sizeof(Student));
        if(!strcmp(myStudent.lastname, lastName)) {
            posElement = i;
            break;
        }
    }
    close(fd);
    if(posElement == -1) {
        printf("No se encontro el valor unu\n");
    } else {
        Student myStudent;
        int lastNameMaxSize = sizeof(myStudent.lastname);
        char trunLastName[lastNameMaxSize];
        strncpy(trunLastName, newLastName, lastNameMaxSize);
        int fd = open(fileName, O_WRONLY);
        lseek(fd, posElement*sizeof(Student) + sizeof(myStudent.name), SEEK_SET);
        write(fd, trunLastName, lastNameMaxSize);
        close(fd);
    }
}
