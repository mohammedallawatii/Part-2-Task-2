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
   // Define global variables
char filename[] = "FitnessData_2023.csv"; // open file
FITNESS_DATA *data;
int numRecords;

// import data from a file
int importData() {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file\n");
        return 1;
    }
}

// Function to display menu and handle user input
void displayMenu() {
    int option = -1;
    while (option != 'Q') {
        printf("\n** Fitness Data Analysis Tool **\n\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n\n");

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'A':
                importData();
                break;
            case 'B':
                displayTotalRecords();
                break;
            case 'C':
                findFewestSteps();
                break;
            case 'D':
                findLargestSteps();
                break;
            case 'E':
                printf("Mean step count: %d\n", calculateMeanSteps());
                break;
            case 'F':
                findLongestPeriodAbove500();
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    }
}
}

