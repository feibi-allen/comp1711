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

int check(FitnessData *dataRecord, int lineNum){
    for (int i = 0; i < lineNum; i ++){
            if (dataRecord[i].steps == 0){
                return 1;
            }else if (strlen(dataRecord[i].date) != 10){
                return 1;
            }else if (strlen(dataRecord[i].time) != 5){
                return 1;
            }
    }
    return 0;
}

int sort(FitnessData *dataRecord, int lineNum){
    while (1){
        int changeMade = 0;
        for (int i = 0; i < lineNum-1; i++){
            if (dataRecord[i].steps<dataRecord[i+1].steps){
                int temp = dataRecord[i].steps;
                dataRecord[i].steps = dataRecord[i+1].steps;
                dataRecord[i+1].steps = temp;
                changeMade = 1;
            }
        }
        if (changeMade != 1){
            return 0;
        }
    }
}

int main() {
    FitnessData dataRecord[200];
    char fileName[30],steps;

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
            tokeniseRecord(line, ',', dataRecord[lineNum].date, dataRecord[lineNum].time, &dataRecord[lineNum].steps);
            lineNum++;
        }
        fclose(dataFile);

        if (check(dataRecord, lineNum) == 1){
            printf("Error: invalid file\n");
            return 1;
            }

        sort(dataRecord,lineNum);
;
        FILE *sortedDataFile = fopen(strcat(fileName,".tsv"), "w");
        for (int i = 0; i < lineNum; i++){
            fprintf(sortedDataFile, "%s\t%s\t%d\n", dataRecord[i].date,dataRecord[i].time,dataRecord[i].steps);
        }
        fclose(sortedDataFile);
        }
    return 0;
}