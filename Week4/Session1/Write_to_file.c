#include <stdio.h>
int main(){
    char myFile [] = "WriteFile.txt";
    FILE *file = fopen(myFile, "w");
    if (file == NULL) {
        perror("");
        return 1;
    }
    int number, num_lines = 10;
    printf("Type %d numbers: ",num_lines);
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
    }
    fclose(file);
    return 0;
}