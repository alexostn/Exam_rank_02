/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
	{
	int	 c = *a;//only c is int(not a pointer)
		*a = *b;
		*b = c;
	}

	// #include <stdio.h>

	// int	main()
	// {
	// 	int a = 3;
	// 	int b = 7;

	// 	printf("a: %d\n", a);
	// 	printf("b: %d\n", b);
	// 	ft_swap(&a, &b);
	// 	printf("___after swap___\n");
	// 	printf("a: %d\n", a);
	// 	printf("b: %d\n", b);
	// 	return (0);
	// }
