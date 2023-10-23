#include <stdio.h>
int main(){
    char myFile [] = "WriteFile.txt";
    FILE *file = fopen(myFile, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }
    int sizeOfALineInTheFile = 100;
    char oneLineStoredAsString[sizeOfALineInTheFile];
    while (fgets(oneLineStoredAsString, sizeOfALineInTheFile, file) != NULL) {
        printf("%s", oneLineStoredAsString); // for each line in the file as long as its not end of file make it into a string and print it
    }
    fclose(file);
    return 0;
}
    