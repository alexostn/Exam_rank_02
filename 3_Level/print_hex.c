/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int ft_atoi(char *str)
{
int res = 0;//DONT FORGET TO INITIALIZE = 0
int sign = 1;

while (*str <= 32)// or while (*str == ' ' || (*str >= 9 && *str <= 13)) to be more precise

	str++;
if (*str == '-' || *str == '+')
	str++;
if (*str == '-')
	sign = -1;
while (*str)
	res = res * 10 + *str++ -48;
return (res * sign);
}



void putchar_hex(char c)
{
	char *arr = "0123456789abcdef";

	write(1, &arr[(int)c], 1);
}

void putnum (int num)
{
	if(num >= 16)
		putnum(num / 16);
	putchar_hex(num % 16);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		putnum(ft_atoi(av[1]));
	}

write (1, "\n", 1);
return (0);
}
