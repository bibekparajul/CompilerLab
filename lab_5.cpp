#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void FIRST(char[], char); // Function prototype for calculating the FIRST set
void addToResultSet(char[], char); // Function prototype for adding characters to the result set

int numOfProductions; // Number of production rules
char productionSet[10][10]; // Array to store production rules

int main() {
    int i;
    char choice;
    char c;
    char result[20]; // Array to store the result (FIRST set)
    printf("--To find First--\n");

    printf("How many number of productions? : ");
    scanf("%d", &numOfProductions); // Input the number of production rules

    for (i = 0; i < numOfProductions; i++) {
        printf("Enter production Number %d: ", i + 1);
        scanf(" %s", productionSet[i]); // Input each production rule
    }

    do {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c); // Input the non-terminal symbol to find the FIRST set for
        FIRST(result, c); // Call the FIRST function to calculate the FIRST set
        printf("\nFIRST(%c) = { ", c);

        for (i = 0; result[i] != '\0'; i++) {
            printf("%c ", result[i]); // Print the calculated FIRST set
        }

        printf("}\nPress 'y' to continue: ");

        // Clear the input buffer
        while ((getchar()) != '\n');

        scanf(" %c", &choice); // Check if the user wants to continue
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to calculate the FIRST set for a given non-terminal symbol
void FIRST(char* Result, char c) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (!(isupper(c))) { // If the symbol is a terminal, add it to the FIRST set
        addToResultSet(Result, c);
        return;
    }

    for (i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == c) {
            if (productionSet[i][2] == '$') {
                addToResultSet(Result, '$'); // Add epsilon to the FIRST set of the non-terminal
            } else {
                j = 2;

                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]); // Calculate FIRST for a symbol in a production

                    // Add the symbols from subResult to Result
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                    }

                    // Check if epsilon ('$') is in subResult
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    if (!foundEpsilon) {
                        break;
                    }

                    j++;
                }
            }
        }
    }
}

// Function to add a character to the result set (avoiding duplicates)
void addToResultSet(char Result[], char val) {
    int k;

    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val) {
            return; // If val is already in the result set, return without adding it again
        }
    }

    Result[k] = val; // Add val to the result set
    Result[k + 1] = '\0'; // Null-terminate the result set
}

