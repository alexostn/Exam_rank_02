/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>


int	ft_atoi(char *ch)
	{
		int res = 0;//do not forget initialize, that matters!!!

		while (*ch <= 32)
			ch++;
		// if (*ch == '+' || *ch == '-') unnecessary as we checked it in main already
		// 	ch++;
		while (*ch >= '0' && *ch <= '9')
			res = res * 10 + *ch++ - 48;

		return (res);
	}

void putchar(char c)
{
	write(1, &c, 1);
}

void putnum(int num)
{
	if (num >= 10)
		putnum (num / 10);
	putchar(num % 10 + 48);	
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 1;
		int num = ft_atoi(av[1]);
		if (num > 0)//"parameter will always be a strictly positive number"
		{
			while (i <= 9 && num <= 238609183)//MAX_INT devided by 9
			{
				putnum(i);
				write(1, " x ", 3);
				putnum(num);
				// write(1, &av[1], 1);that will not work correctly, but putnum(num); will
				write(1, " = ", 3);
				putnum(i * num);
				if (i < 9)// Only write a newline if it's not the last line
					write(1, "\n", 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
