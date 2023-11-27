#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

// My functions
int FindFewestLine(FITNESS_DATA *dataRecord, int lineNum){
	int targetLine = 0, fewestSteps = dataRecord[0].steps;
	for (int i=1; i < lineNum; i++){
		if (dataRecord[i].steps <= fewestSteps){
			targetLine = i;
			fewestSteps = dataRecord[i].steps;
		}
	}
	return targetLine;
}

int FindLargestLine(FITNESS_DATA *dataRecord, int lineNum){
	int targetLine = 0, mostSteps = dataRecord[0].steps;
	for (int i = 1; i < lineNum; i++){
		if (dataRecord[i].steps >= mostSteps){
			targetLine = i;
			mostSteps = dataRecord[i].steps;
		}
	}
	return targetLine;
}


#endif // FITNESS_DATA_STRUCT_H