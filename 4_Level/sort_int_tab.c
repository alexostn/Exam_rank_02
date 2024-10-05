/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned	int i;
	unsigned	int j;
	int	temp;
	int	flag = 0; // Flag to check if a swap was made

	i = 0;
	while (i < size)
	{
		j = 0;//0 on each iteration of INNER CIRCLE
		while (j < size - 1)//size-1 it is the last element, first is 0
		{
			if (tab[j] > tab[j +1])
			{
				temp = tab[j];
				tab[j] = tab[j +1];
				tab[j + 1] = temp;
				flag = 1;
			}
			j++;//go to the next pair of elements
		}
		if (flag == 0)
			break;
		i++;//go the next iteration of OUTER CIRCLE
	}
}

// int	main ()
// {
// 	int tab[] = {3, 5, 7, 8, 0, 9};
// 	unsigned int	size = sizeof (tab)/sizeof (tab[0]);
// 	unsigned int	i;

// 	sort_int_tab(tab, size);

// 	for (i = 0; i < size; i++)
// 	{
// 		printf("%d", tab[i]);
// 	}
// 	return (0);
// }

#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned int size = argc - 1; //Ammount of elements in array
	int tab[size]; // fixed array

	// Convert string arguments to integers
	for (unsigned int i = 0; i < size; i++)
	{
		tab[i] = atoi(argv[i + 1]); //Convert string to int
	}

	sort_int_tab(tab, size);  // Sort the array

	printf("Sorted array:\n");
	for (unsigned int i = 0; i < size; i++)
	{
		printf("%d ", tab[i]); // Print the sorted array
	}
	printf("\n");

	return 0;
}
