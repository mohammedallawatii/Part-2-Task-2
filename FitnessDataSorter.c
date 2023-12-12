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


int main() {
    char filename[100];
    char outputFilename[105];
    FILE *file;
    FitnessData data[1000]; // Adjust size as needed
    int count = 0;

    // 1. Prompt for Filename
    printf("Enter filename:\n");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: invalid file\n");
        return 1;
    }

    // 2. File Validation and Reading
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        // Tokenize and store data
        tokeniseRecord(line, ',', data[count].date, data[count].time, &data[count].steps);
        
        // Validate data
        if (strlen(data[count].date) != 10 || strlen(data[count].time) != 5) {
            printf("Error: invalid file\n");
            fclose(file);
            return 1;
        }
        count++;
    }
    fclose(file);

    // 3. Sorting the Data
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) {
                FitnessData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // 4. Writing to Output File
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");
    file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error: Could not create output file\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(file);

    // 5. Successful Completion
    return 0;
    
}