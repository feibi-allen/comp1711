#include <stdio.h>

typedef struct {  // giving the "struct student" a new name "student"
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

void printStudents(student * students, int num_students){
        for (int i = 0; i < num_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
}

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10;
    student students [] = {  // now no longer need to use struct before student
        {"Alice Smith",    "64827593", 67}, // making an array of student structures
        {"Bob Johnson",    "19374650", 89},
        {"Charlie Brown",  "82056914", 76},
        {"David Davis",    "45790182", 44},
        {"Eve Wilson",     "36102478", 91},
        {"Frank Anderson", "93571826", 53},
        {"Grace Lee",      "50249867", 78},
        {"Hannah Clark",   "74820591", 62},
        {"Isaac Harris",   "61093745", 89},
        {"Jack White",     "92847501", 72},
    };
    printStudents(students,number_of_students);
    
    return 0;
}