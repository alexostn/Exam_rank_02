/*
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/
#include <unistd.h>
void putnum(int num)
{
	char res;//instead of using putchar
	if (num >= 10)
		putnum (num / 10);
	res = num % 10 + 48;
	write(1, &res, 1);//instead of using putchar
}

int	main(int ac, char *av[])
{
	(void)av;//to declare that this parametr will not be used

	if (ac > 1)
	{

		putnum(ac - 1);
	}
	write(1, "\n", 1);
	return (0);
}
