//SIMPLIFIED VERSION
#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
    // Allocate memory for a large number of string pointers
    char **arr = malloc(sizeof(char *) * 10000000);
    int i = 0;

    // Skip initial spaces and tab characters
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))//!!!works with this precision only
        i++;

    int x = 0; // Index for word in the array
    int y = 0; // Index for character in the current word

    // Main loop to iterate through the input string
    while (str[i])
    {
        // Allocate memory for each word if it hasn't been allocated yet
        if (arr[x] == NULL)
            arr[x] = malloc(sizeof(char) * 1000000);

        // Add the current character to the current word
        arr[x][y] = str[i];
        y++;
        i++;

        // If a space or tab is encountered, the word ends
        if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))//!!!works with this precision only
        {
            // Null-terminate the current word
            arr[x][y] = '\0';
            x++; // Move to the next word in the array
            y = 0; // Reset the character index for the new word

            // Skip spaces and tabs between words
            while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        }
    }

    // Null-terminate the last word
    arr[x][y] = '\0';

    // Mark the end of the array with a NULL pointer
    arr[x + 1] = NULL;

    return arr;
}

// int main()
// {
//     // Test string with multiple lines and words
//     char **arr = ft_split("All movement is accomplished in six stages\n"
//     "And the seventh brings return\n"
//     "The seven is the number of the young light\n"
//     "It forms when darkness is increased by one");

//     // Print each word and its index
//     for (int i = 0; arr[i]; i++)
//     {
//         // Print the current word and its index
//         printf("%s %d\n", arr[i], i);

//         // Free memory allocated for each word
//         free(arr[i]);
//     }

//     // Free the array of pointers
//     free(arr);
// }

