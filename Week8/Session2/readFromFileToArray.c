#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_STUDENTS 10
#define N_MARKS 3

int main(){
    FILE *marksFile = fopen("marks.txt", "r");

    int marks[N_STUDENTS][N_MARKS], lineLen = (500), values[N_STUDENTS*N_MARKS];
    char line[lineLen];

    while (fgets(line, lineLen, marksFile))
    {
        char *marksCopy = strdup(line);
        char *token = strtok(marksCopy, ",");
        int i = 0;

        while (token != NULL && i < lineLen) {
            values[i++] = atoi(token);
            token = strtok(NULL, ",");
        }

    // Free the memory allocated by strdup
    free(marksCopy);
    }

    for (int i = 0; i<N_MARKS*N_STUDENTS;i++){
        marks[i/3][i%3] = values[i];
    }
    for (int i = 0; i <N_STUDENTS;i++){
        printf("Student %d: %d %d %d\n", i, marks[i][0],marks[i][1],marks[i][2]);
    }
}