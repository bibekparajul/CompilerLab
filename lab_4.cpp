#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
char keyword[32][10] = {
    "auto", "double", "int", "struct", "break", "else", "long", "float", "short", "unsigned", "continue", "switch", "case",
    "enum", "register", "typedef", "char", "extern", "return", "union", "const", "for", "signed", "void", "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"
};

// Function to check if a given string is a C keyword
int iskeyword(char str[]) {
    int i;
    for (i = 0; i < 32; i++) {
        if (strcmp(str, keyword[i]) == 0)
            return 1; // It's a keyword
    }
    return 0; // It's not a keyword
}

int main() {
    printf("--Lexical Analyzer--");
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;
    
    fp = fopen("lex_check.txt", "r"); // Open the file for reading
    
    if (fp == NULL) {
        printf("Error while opening the file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) { // Read characters from the file until EOF is reached
        for (i = 0; i < 6; ++i) {
            if (ch == operators[i]) {
                printf("\n%c is an operator\n", ch);
            }
        }
        if (isalnum(ch)) { // Check if the character is alphanumeric (letter or digit)
            buffer[j++] = ch; // Add it to the buffer
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0'; // Null-terminate the buffer
            j = 0;
            if (iskeyword(buffer) == 1) {
                printf("\n%s is a keyword", buffer);
            } else {
                printf("\n%s is an identifier", buffer);
            }
        }
    }

    fclose(fp); // Close the file
    
    return 0;
}

