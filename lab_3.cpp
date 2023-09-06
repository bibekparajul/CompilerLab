#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char a[100];
    int flag, i = 1;
    char choice;
    printf("--To check whether identifier is valid or not--");

    do
    {
        printf("\nEnter an identifier: ");
        gets(a); // Read the user input as an identifier

        // Check if the first character is an alphabet or underscore
        if (isalpha(a[0]) || a[0] == '_')
            flag = 1; // Set flag to 1 if the identifier starts correctly
        else
        {
            printf("\nNot a valid identifier.\n");
            continue; // Skip the rest of the loop and start over
        }

        // Loop through the remaining characters in the identifier
        while (a[i] != '\0')
        {
            // Check if the character is a digit, alphabet, or underscore
            if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_')
            {
                flag = 0; // If any character is invalid, set flag to 0
                break;
            }
            i++;
        }

        // Print the result based on the flag value
        if (flag == 1)
            printf("Valid Identifier\n");
        else
            printf("Not a valid identifier\n");

        // Ask if the user wants to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character
        getchar(); // Consume the newline character left in the input buffer

    } while (choice == 'y' || choice == 'Y'); // Continue loop if choice is 'y' or 'Y'

    return 0;
}

