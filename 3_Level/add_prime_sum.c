/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>

int ft_atoi(char *c)
{
	int	res = 0;

	if (*c == '-')
		return (0);
	while (*c >= '0' && *c <= '9')
		res = res * 10 + *c++ - 48;
	return (res);
}

int is_prime(int n)
{
	if (n <= 1)
		return (0);
	int i = 2;
	while (i * i <= n)
		{
		if (n % i == 0)
			return (0);
		i++;
		}
	return (1);
}

void	putnum(int nu)
{
	char ch;
	if (nu >= 10)
		putnum(nu / 10);
	ch = (nu % 10) + '0';
	write(1, &ch, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}

	if (ac == 2)
	{
		int num = ft_atoi(av[1]);
		int sum = 0;
		int i = 2;

		if (num <= 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		
		while (i <= num)
		{
			if (is_prime(i))
			{
			sum = i + sum;
			}
		i++;
		}
		putnum(sum);
	}
	write(1, "\n", 1);
	return (0);
}
