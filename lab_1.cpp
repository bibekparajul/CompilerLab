#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    char comment[50];  // Declare a character array to store the comment
    int i, a = 0, length;  // Declare integer variables for looping and flag
    char choice;  // Declare a character variable for user choice

    printf("--To check whether entered string is a valid comment or not--\n");

    do {
        printf("Enter comment: ");
        gets(comment);  // Read a line of text (comment) from the user

        length = strlen(comment);  // Get the length of the entered comment

        if (comment[0] == '/')  // Check if the first character is '/'
        {
            if (comment[1] == '/')  // Check if the second character is also '/'
            {
                printf("It is a single-line comment.\n");  // It's a single-line comment
            }
            else if (comment[1] == '*')  // Check if the second character is '*'
            {
                for (i = 2; i < length - 1; i++) 
                {
                    if (comment[i] == '*' && comment[i + 1] == '/') 
                    {
                        printf("It is a multi-line comment.\n");  // It's a multi-line comment
                        a = 1;
                        break;
                    }
                }
                if (a == 0) 
                {
                    printf("It is not a comment.\n");  // It's not a valid comment
                }
            }
            else
            {
                printf("It is not a comment.\n");  // It's not a valid comment
            }
        }
        else
        {
            printf("It is not a comment.\n");  // It's not a valid comment
        }

        // Ask if the user wants to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);  // Read the user's choice (space before %c to skip newline)
        getchar(); // Clear the newline character from the input buffer

    } while (choice == 'y' || choice == 'Y');  // Continue if the user enters 'y' or 'Y'

    printf("Program halted.\n");  // Print a message indicating program termination

    return 0;
}

