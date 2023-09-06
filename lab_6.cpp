#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, i = 0, j = 0;
char a[10][10], Result[10] = {'\0'};
char subResult[20] = {'\0'};

// Function prototypes
void follow(char *Result, char c);
void first(char *Result, char c);
void addToResultSet(char[], char);

int main() {
    int choice;
    char c;
    printf("--To find FOLLOW--\n");
    printf("Enter the no. of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions\nProduction with multiple terms should be given as separate productions\n", n);

    // Input the production rules
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    do {
        printf("Find FOLLOW of --> ");
        scanf(" %c", &c); // Notice the space before %c to consume whitespace
        follow(Result, c);
        printf("FOLLOW (%c) = { ", c);
        
        // Print the calculated FOLLOW set
        for (i = 0; Result[i] != '\0'; i++)
            printf("%c", Result[i]);
        printf(" }\n");
        
        printf("Do you want to continue (Press 1 to continue...)?");
        scanf("%d", &choice);
    } while (choice == 1);
}

// Function to calculate the FOLLOW set for a non-terminal symbol
void follow(char *Result, char c) {
    int k;
    subResult[0] = '\0';
    
    // If the first production starts with 'c', add '$' to the FOLLOW set
    if (a[0][0] == c)
        addToResultSet(Result, '$');
    
    // Iterate through the productions
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0')
                    first(subResult, a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(subResult, a[i][0]);
                for (k = 0; subResult[k] != '\0'; k++)
                    addToResultSet(Result, subResult[k]);
            }
        }
    }
}

// Function to calculate the FIRST set for a symbol
void first(char *R, char c) {
    int k, m;
    if (!(isupper(c)) && c != '#')
        addToResultSet(R, c);
    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '#' && c != a[k][0])
                follow(R, a[k][0]);
            else if (!(isupper(a[k][2])) && a[k][2] != '#')
                addToResultSet(R, a[k][2]);
            else
                first(R, a[k][2]);
            for (m = 0; R[m] != '\0'; m++)
                addToResultSet(Result, R[m]);
        }
    }
}

// Function to add a character to the result set (avoiding duplicates)
void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val)
            return; // If val is already in the result set, return without adding it again
    }
    Result[k] = val; // Add val to the result set
    Result[k + 1] = '\0'; // Null-terminate the result set
}

