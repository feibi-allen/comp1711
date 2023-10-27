#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student student1Profile = {.student_id = "28932123", 35, .name = "Feibi Allen"}; // can put in order or can use designator (.name)
    printf("Student name: %s\n", student1Profile.name);
    printf("Student ID:   %s\n", student1Profile.student_id);
    printf("Final mark:   %u\n", student1Profile.mark);
    return 0;
}