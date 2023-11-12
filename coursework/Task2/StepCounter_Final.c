#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    char option, fileName[30];
    int lineNum = 0;
    char date[11], time[6], steps[10];
    FITNESS_DATA dataRecord[100];

    int runMenue = 0;

    while (runMenue == 0){
    
        printf(
        "Menue Options:\n"
        "A: Specify the filename to be imported \n"
        "B: Display the total number of records in the file\n"
        "C: Find the date and time of the timeslot with the fewest steps\n"
        "D: Find the data and time of the timeslot with the largest number of steps\n"
        "E: Find the mean step count of all the records in the file\n"
        "F: Find the longest continuous period where the step count is above 500 steps\n"
        "Q: Exit\n"
        );

        scanf("%s", &option);

        switch (option){
            case 'A':
                    printf("Input filename:\n");
                    scanf("%s", fileName);

                    FILE *dataFile = fopen(fileName, "r");

                    if (dataFile == NULL) {
                        perror("Error: Could not find or open file");
                        return 1;
                    }

                    else{
                        lineNum = 0;
                        int lineLength = 30;
                        char line[lineLength];
                        while (fgets(line , lineLength, dataFile)){
                        tokeniseRecord(line, ",", date, time, steps);
                        strcpy(dataRecord[lineNum].date, date);
                        strcpy(dataRecord[lineNum].time, time);
                        dataRecord[lineNum].steps = atoi(steps);
                        lineNum++;
                        }
                        printf("File successfully loaded.\n");
                    }
                    break;

            case 'B': printf("Total records:%d\n", lineNum);
                    break;
        
            case 'C': 
                    {int targetLine, fewestNumSteps = 100000;
                    for (int i = 0; i <= lineNum; i++){
                        if (dataRecord[i].steps < fewestNumSteps){
                            targetLine = i;
                            fewestNumSteps = dataRecord[targetLine].steps;
                        }
                    }
                    printf("Fewest steps: %s %s\n", dataRecord[targetLine].date, dataRecord[targetLine].time);
                    }
                    break;
        
            case 'D': printf("Largest steps:\n");
                    runMenue = 1;
                    break;

            case 'E': printf("Mean step count:\n");
                    runMenue = 1;
                    break;
        
            case 'F': printf("Longest period start:\nLongest period end:\n ");
                    runMenue = 1;
                    break;

            case 'Q': runMenue = 1;
                    break;

            default: printf("Invalid choice. Try again.\n"); 
                    break;
        }
    }
}