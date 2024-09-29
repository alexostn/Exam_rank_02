#include <stdio.h>
#include <stdlib.h>

char	*ft_create_hex_array(int number)
{
	char	*array;
	int		i;

	if (number < 1 || number > 16) // Check for valid range
		return (NULL);

	array = (char *)malloc((number + 1) * sizeof(char)); // +1 for the null terminator
	if (array == NULL)
		return (NULL);

	for (i = 0; i < number; i++)
	{
		if (i < 10)
			array[i] = '0' + i; // Fill with characters from '0' to '9'
		else
			array[i] = 'a' + (i - 10); // Fill with characters from 'a' to 'f'
	}
	array[number] = '\0'; // Terminate the string with a null character

	return (array);
}

int main()
{
	int number;
	char *hex_array;

	printf("Enter a number (1-16): ");
	scanf("%d", &number); // Read the number

	hex_array = ft_create_hex_array(number); // Create the array of hexadecimal characters
	if (hex_array == NULL)
	{
		printf("Error: the number must be between 1 and 16.\n");
		return (1);
	}

	printf("Created array of hexadecimal numbers: %s\n", hex_array); // Print the array
	free(hex_array); // Free the memory
	return (0);
}
