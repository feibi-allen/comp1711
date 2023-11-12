#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    char fitnessDataFile [] = "FitnessData_2023.csv";
    FILE *dataFile = fopen(fitnessDataFile, "r");
    if (dataFile == NULL) {
        perror("");
        return 1;
    }

    FITNESS_DATA dataRecord[100];

    int lineLength = 30, lineNum = 0;
    char line[lineLength];
    char date[11] , time[6], steps[10];

    while (fgets(line , lineLength, dataFile)){
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(dataRecord[lineNum].date, date);
        strcpy(dataRecord[lineNum].time, time);
        dataRecord[lineNum].steps = atoi(steps);
        lineNum++;
    }
    printf("Number of records in file: %d\n", lineNum);
    for (int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", dataRecord[i].date, dataRecord[i].time, dataRecord[i].steps);
    }
    fclose(dataFile);

    return 0;
}