/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i = 0;
	int len = abs((end - start)) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start + len - 1;//the difference between ft_range/ + len - 1
			start--;//--
			i++;
		}
		else//this case stays the same
		{
			res[i] = start;
			start--;
			i++;
		}
	}
        return (res);
}

#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int *result;
        int start = atoi(av[1]);
        int end = atoi(av[2]);
        int len = abs(end - start) + 1;
        int i;

        result = ft_range(start, end);
        for (i = 0; i < len; i++)
        {
            printf("%d ", result[i]);
            // if (i < len - 1)//for commas
            // {
            //     printf(", ");
            // }
        }
        printf("\n");
		free(result);  // free memory
    }
    return (0);
}
