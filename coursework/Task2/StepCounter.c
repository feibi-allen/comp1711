#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

FITNESS_DATA dataRecord[200];
int lineNum;

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

    while (1){
    
        printf(
        "Menue Options:\n"
        "A: Specify the filename to be imported \n"
        "B: Display the total number of records in the file\n"
        "C: Find the date and time of the timeslot with the fewest steps\n"
        "D: Find the data and time of the timeslot with the largest number of steps\n"
        "E: Find the mean step count of all the records in the file\n"
        "F: Find the longest continuous period where the step count is above 500 steps\n"
        "Q: Exit\n"
        "Enter choice: ");

        scanf("%s", &option);

        switch (option){
            case 'A':
                    printf("Input filename: ");
                    char fileName[30], steps[10];
                    scanf("%s", fileName);

                    FILE *dataFile = fopen(fileName, "r");

                    if (!dataFile) {
                        printf("Error: Could not find or open file\n");
                        return 1;
                    }

                    else {
                        lineNum = 0;
                        int lineLength = 30;
                        char line[lineLength];

                        while (fgets(line, lineLength, dataFile)){
                            tokeniseRecord(line, ",", dataRecord[lineNum].date, dataRecord[lineNum].time, steps);
                            dataRecord[lineNum].steps = atoi(steps);
                            lineNum++;
                        }
                        fclose(dataFile);
                        printf("File successfully loaded.\n");
                    }
                    break;

            case 'B': 
                    printf("Total records: %d\n", lineNum);
                    break;
        
            case 'C':
                    printf("Fewest steps: %s %s\n", dataRecord[FindFewestLine(dataRecord,lineNum)].date,dataRecord[FindFewestLine(dataRecord,lineNum)].time);
                    break;
        
            case 'D':
                    printf("Largest steps: %s %s\n", dataRecord[FindLargestLine(dataRecord,lineNum)].date,dataRecord[FindLargestLine(dataRecord,lineNum)].time);
                    break;

            case 'E':
                    printf("Mean step count: %d\n", calcMean(dataRecord, lineNum));
                    break;
        
            case 'F':
                    {int fivehundredFound = 0, startLine, endLine, tempStartLine, tempEndLine;
	                for (int i = 0; i < lineNum; i++){
		                if (dataRecord[i].steps > 500 && fivehundredFound == 0){
			                tempStartLine = i;
			                fivehundredFound = 1;
		                }
		                else if (dataRecord[i].steps <= 500 && fivehundredFound == 1){
			                tempEndLine = i - 1;
			                fivehundredFound = 0;
			                if ((tempEndLine-tempStartLine) >= (endLine-startLine)){
				                endLine = tempEndLine;
				                startLine = tempStartLine;
			                }
		                }
	                }
	                printf("Longest period start: %s %s\n", dataRecord[startLine].date, dataRecord[startLine].time);
	                printf("Longest period end: %s %s\n", dataRecord[endLine].date, dataRecord[endLine].time);}
                    break;

            case 'Q':
                    return 1;
                    break;

            default: printf("Invalid choice. Try again.\n"); 
                    break;
        }
    }
}