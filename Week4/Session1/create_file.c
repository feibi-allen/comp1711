#include <stdio.h>
int main(){
    char myFile [] = "NewFile.txt";
    FILE *file = fopen(myFile, "w");
    if (file == NULL) {
        perror("");
        return 1;
    }
    fclose(file);
    return 0;
}