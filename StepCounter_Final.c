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
// Define global variables
void displayMenu() {
    printf("\nMenu Options:\n");
  printf("A: Specify the filename to be imported\n");
  printf("B: Display the total number of records in the file\n");
  printf("C: Find the date and time of the timeslot with the fewest steps\n");
  printf("D: Find the date and time of the timeslot with the largest number of steps\n");
  printf("E: Find the mean step count of all the records in the file\n");
  printf("F: Find the longest continuous period where the step count is above 500 steps\n");
  printf("Q: Quit\n");
  printf("Enter choice: ");
}

int fileInput() {
    char filename[100];

    
    printf("Input filename: ");
    scanf("%s", filename);
    if (strcmp(filename, "FitnessData_2023.csv") != 0) {
        fprintf(stderr, "Incorrectly named data file\n");
        return 1;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not find or open file\n");
    }

fclose(file);

return 0;
}

void numberOfRecords() {
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        exit(1);
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
     printf("Total records: %d\n", rows); // printing the number of rows
}

void fewestSteps() {
    // make a filname for the data
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        exit(1);
    }
    char line[100];  // the line[100] means that the line will not be more that 100 characters
    int rows = 0; // create counter for the number of rows

    char date[100];
    char time[100]; // making an array 
    char steps[100];
    int stepArray[100];

    FITNESS_DATA data[100];

    while(fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps); // use function to seperate lines
        strcpy(data[rows].date, date); // storing the data in a list
        strcpy(data[rows].time, time);
        data[rows].steps = atoi(steps);
        stepArray[rows] = atoi(steps);
        rows++; // increment number of rows
    }

    int smallest = stepArray[0]; // Assume the first element is the smallest
    int index_of_smallest = 0; // Index of the smallest number

    for (int i = 1; i < rows; i++) {
        if (stepArray[i] < smallest) {
            smallest = stepArray[i];
            index_of_smallest = i;
        }
    }
    
    printf("Fewest steps: %s %s\n", data[index_of_smallest].date, data[index_of_smallest].time); // printing the number of rows
}

void largestSteps() {
    // make a filname for the data
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        exit(1);
    }
    char line[100];  // the line[100] means that the line will not be more that 100 characters
    int rows = 0; // create counter for the number of rows

    char date[100];
    char time[100]; // making an array 
    char steps[100];
    int stepArray[100];

    FITNESS_DATA data[100];

    while(fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps); // use function to seperate lines
        strcpy(data[rows].date, date); // storing the data in a list
        strcpy(data[rows].time, time);
        data[rows].steps = atoi(steps);
        stepArray[rows] = atoi(steps);
        rows++; // increment number of rows
    }

    int largest = stepArray[0]; // Assume the first element is the smallest
    int index_of_largest = 0; // Index of the smallest number

    for (int i = 1; i < rows; i++) {
        if (stepArray[i] > largest) {
            largest = stepArray[i];
            index_of_largest = i;
        }
    }
    
    printf("Fewest steps: %s %s\n", data[index_of_largest].date, data[index_of_largest].time); // printing the number of rows
}

void meanNumber() {
    // make a filname for the data
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        exit(1);
    }
    char line[100];  // the line[100] means that the line will not be more that 100 characters
    int rows = 0; // create counter for the number of rows

    char date[100];
    char time[100]; // making an array 
    char steps[100];
    int stepArray[100];

    FITNESS_DATA data[100];

    while(fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps); // use function to seperate lines
        strcpy(data[rows].date, date); // storing the data in a list
        strcpy(data[rows].time, time);
        data[rows].steps = atoi(steps);
        stepArray[rows] = atoi(steps);
        rows++; // increment number of rows
    }
    
    int sum = 0;
    int mean;

    for (int i = 0; i < rows; i++) {
        sum += stepArray[i];
    }

    // Calculate the mean
    mean = (int)sum / rows;

    printf("Mean step count: %d\n", mean);

}

void longestPeriod() {
// make a filname for the data
    const char *filename = "FitnessData_2023.csv";

    // open the file with as reading only and if it is not there a message will be diplayed which shows that there is no file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the file %s\n", filename);
        exit(1);
    }
    char line[100];  // the line[100] means that the line will not be more that 100 characters
    int rows = 0; // create counter for the number of rows

    char date[100];
    char time[100]; // making an array 
    char steps[100];
    int stepArray[100];

    FITNESS_DATA data[100];

    while(fgets(line, 100, file) != NULL) {
        tokeniseRecord(line, ",", date, time, steps); // use function to seperate lines
        strcpy(data[rows].date, date); // storing the data in a list
        strcpy(data[rows].time, time);
        data[rows].steps = atoi(steps);
        stepArray[rows] = atoi(steps);
        rows++; // increment number of rows
    }

    int currentStart = 0;
    int maxStart = 0;
    int maxLength = 0;
    int currentLength = 0;
    int endIndex = 0;
    int startIndex = 0;
    int threshold = 500;

    for (int i = 0; i < rows; i++) {
        if (stepArray[i] > threshold) {
            if (currentLength == 0) {
                currentStart = i; // Start of a new sequence
            }
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStart = currentStart;
                endIndex = i - 1;
            }
            currentLength = 0; // Reset for the next sequence
        }
    }

    // Check for the case where the longest sequence is at the end of the array
    if (currentLength > maxLength) {
        maxLength = currentLength;
        maxStart = currentStart;
        endIndex = rows - 1;
    }

    startIndex = maxStart;

    printf("Longest period start: %s %s\n", data[startIndex].date, data[startIndex].time);
    printf("Longest period end: %s %s\n", data[endIndex].date, data[endIndex].time);
}

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
   
   int answer;
   char choice;

   do{
    displayMenu();
    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
        case 'A':
            answer = fileInput();
            if (answer == 0) {
                printf("File successfully loaded.\n");
            }
            break;
        case 'b':
        case 'B':
            numberOfRecords();
            break;
        case 'c':
        case 'C':
            fewestSteps();
            break;
        case 'd':
        case 'D':
            largestSteps();
            break;
        case 'e':
        case 'E':
            meanNumber();
            break;
        case 'f':
        case 'F':
            longestPeriod();
            break;
        case 'q':
        case 'Q':
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }
   } while(choice != 'Q' && choice != 'q');

     
    return 0;
          
      
}
