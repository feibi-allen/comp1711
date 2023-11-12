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
    char option;
    int runMenue = 0;

    while (runMenue == 0){
    
        printf(
        "A: Specify the filename to be imported \n"
        "B: Display the total number of records in the file\n"
        "C: Find the date and time of the timeslot with the fewest steps\n"
        "D: Find the data and time of the timeslot with the largest number of steps\n"
        "E: Find the mean step count of all the records in the file\n"
        "F: Find the longest continuous period where the step count is above 500 steps\n"
        "Q: Exit\n"
        );

        scanf("%c", &option);

        switch (option){
            case 'A': printf("Input filename:\n");
                    char fileName[30];
                    scanf("%s", fileName);
                    FILE *dataFile = fopen(fileName, "r");
                    if (dataFile == NULL) {
                        perror("Error: Could not find or open file");
                        return 1;
                    }
                    else{
                        printf("File successfully loaded.\n");
                    }
                    runMenue = 1;
                    break;

            case 'B': printf("Total records:\n");
                    runMenue = 1;
                    break;
        
            case 'C': printf("Fewest steps\n");
                    runMenue = 1;
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