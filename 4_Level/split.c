#include <stdlib.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2, int ammount)
{
	int i = -1;

	while (++i < ammount && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

// Splits the input string 'str' into words separated by spaces, tabs, or newlines.
// Allocates memory for an array of strings where each element contains a word.
// Returns the array of strings, with the last element being NULL to mark the end.
char    **ft_split(char *str)
{
	int		i = 0;
	int beg = 0;
	int w_out = 0;
	int words_count = 0;

	// First pass: Count the number of words in the input string
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) // Skip over spaces, tabs, or newlines
			i++;
		if (str[i])
			words_count++; // If a word is found ONE TIME EVENT
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')) // Move index to the end of the current word
			i++;
	}

	char **arr_of_str = ((char **)malloc(sizeof (char *) * (words_count + 1)));
	i = 0; // Reset index to traverse the string again
	// Second pass: Extract words and copy them into the output array
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) // Skip over spaces, tabs, or newlines
			i++;
		beg = i; // Mark the start of the word
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')) // Move index to the end of the word
			i++;
		if (i > beg)
		{
			// If a word is found (i > j), allocate memory and copy the word
			arr_of_str[w_out] = (char *)malloc(sizeof (char) * ((i - beg) + 1)); // Allocate memory for the word (length of the word + 1 for '\0')
			ft_strcpy(arr_of_str[w_out++], &str[beg], i - beg);
		}
	}
	arr_of_str[w_out] = NULL;
	return (arr_of_str);
}

// int	main()
// {
// 	char *str = 
// 	"All movement is accomplished in six stages\n"
// 	"And the seventh brings return\n"
// 	"The seven is the number of the young light\n"
// 	"It forms when darkness is increased by one";

// 	// Call ft_split and store the result in an array of strings
// 	char **result = ft_split(str);

// 	// Iterate through the array of strings and print each one with its index
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("Word %d: %s\n", i, result[i]); // Print each word with its index
// 		free(result[i]);  // Free memory for each word
// 		i++;
// 	}

// 	// Free the memory allocated for the array of strings
// 	free(result);
// 	return (0);
// }
