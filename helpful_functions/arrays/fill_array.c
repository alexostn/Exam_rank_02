#include <stdio.h>
#include <stdlib.h>

int	*ft_create_and_fill_array(int number)
{
	int	*array;
	int	i;

	array = (int *)malloc(number * sizeof(int)); // Size of the array from 1 to number
	if (array == NULL)
		return (NULL);

	i = 0;
	while (i < number) // Filling the array with values from 1 to number
	{
		array[i] = i + 1; // Elements from 1 to number
		i++;
	}
	return (array);
}

int main()
{
	char input[10];
	int number;
	int *array;
	int i;

	printf("Enter a number: ");
	fgets(input, sizeof(input), stdin);
	number = atoi(input); // Convert the string to an integer

	array = ft_create_and_fill_array(number); // Create and fill the array
	if (array == NULL)
	{
		printf("Memory allocation error\n");
		return (1);
	}

	printf("Created array: ");
	for (i = 0; i < number; i++)
	{
		printf("%d ", array[i]); // Print the elements of the array
	}
	printf("\n");

	free(array); // Free the memory
	return (0);
}
