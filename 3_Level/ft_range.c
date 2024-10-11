/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

//0. length array iterator
//1.Define size of array (amount of numbers between star and end)
//2.allocate memory for array /NULL case
//3.fill an array /2 cases
//4.return pointer

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	length;
	int	*arr;
	int	i = 0;

	if (start < end)
		length = (end - start) + 1;
	else 
		length = (start - end) + 1;

	arr = (int *)malloc((sizeof (int) * length));
	if (arr == NULL)
		return (NULL);
	if (start < end)
		while (start <= end)
		{
			arr[i] = start;
			start++;
			i++;
		}
	else if (start > end)
		while (start >= end)
		{
			arr[i] = start;
			start--;
			i++;
		}
	return (arr);
}

// #include <stdio.h>

// int main(int ac, char **av)
// {
//     if (ac == 3)
//     {
//         int *result;
//         int start = atoi(av[1]);
//         int end = atoi(av[2]);
//         int len = abs(end - start) + 1; //abs is alternative way of calculating length no matter sign
//         int i;

//         result = ft_range(start, end);
//         for (i = 0; i < len; i++)
//         {
//             printf("%d ", result[i]);
//             // if (i < len - 1)//for commas
//             // {
//             //     printf(", ");
//             // }
//         }
//      printf("\n");
// 	free(result);  // free memory
//     }
//     return (0);
// }

