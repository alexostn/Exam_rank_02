/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

char	*ft_itoa(int n)
{
	int	num = n;//needed to do not change "n"
	int	len = 0;//DONT FORGET TO INITIALIZE!!! = 0
	char *res;//string for return

	if (n == -2147483648)//INT_MIN is special because its absolute value exceeds the range of representable positive values for the int type
		return("-2147483648");//return directly
	if (n <= 0)//for '-' or '0'
		len++;
	while(num != 0)
	{
		num = num / 10;
		len++;
	}
	res = (char*)malloc(sizeof(char) * (len + 1));// +1 for '/0'
	if (res == NULL)
		return(NULL);//checking allocation
	res[len] = '\0';
	num = n;//actualizinng num after length manipulation

	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		num = -num;
		res[0] = '-';//writing '-' symbol to our string array
	}
	
	while (num != 0)
	{
		res[--len] = (num % 10) + 48;
		num = num / 10;
	}
	return (res);
}

#include <stdio.h>
int	main(int	ac, char	**av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));//important to convert argument to int first
	}

}
