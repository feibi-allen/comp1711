#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


void mergeSort(FitnessData *dataRecord,int left, int right, int lineNum){
    if (left != right){
        int middle = left + (right - left)/2;
        mergeSort(dataRecord,left,middle, lineNum);
        mergeSort(dataRecord,middle+1,right, lineNum);
    }
    else if (left + 1  == right && right != (lineNum-1)){
        if (dataRecord[left].steps < dataRecord[right].steps)

    }
}

int main() {
    FitnessData dataRecord[200];
    char fileName[30];
    int steps;

    printf("Input filename: ");
    scanf("%s", fileName);

    FILE *dataFile = fopen(fileName, "r");

    if (!dataFile) {
        printf("Error: Could not find or open file\n");
        return 1;
    }
    else {
        int lineNum = 0;
        int lineLength = 30;
        char line[lineLength];

        while (fgets(line, lineLength, dataFile)){
            tokeniseRecord(line, ",", dataRecord[lineNum].date, dataRecord[lineNum].time, steps);
            dataRecord[lineNum].steps = atoi(steps);
            lineNum++;
            }
        fclose(dataFile);
        }
    
}