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
                void importData() {
                    // make a filname for the data
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        return 1;
    }
    char line[100];  // the line[100] means that the line will not be more that 100 characters
    int rows = 0; // create counter for the number of rows

    char date[100];
    char time[100]; // making an array 
    char steps[100];

    FITNESS_DATA data[100];

    while(fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps); // use function to seperate lines
        strcpy(data[rows].date, date); // storing the data in a list
        strcpy(data[rows].time, time);
        data[rows].steps = atoi(steps);
        rows++; // increment number of rows
    }
}
                break;
            case 'B':
                printf("Total records: %d\n", numRecords);
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


