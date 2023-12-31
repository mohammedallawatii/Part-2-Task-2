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
void diplayMenu();
int fileInput();
void numberOfRecords();
void fewestSteps();
void largestSteps();
void meanNumber();
void longestPeriod();

#endif // FITNESS_DATA_STRUCT_H