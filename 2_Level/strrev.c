/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
// #include <stdio.h>

char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}

// int main()
// {
// 	char str[] = "123456";
// 	printf("%s\n", str);  
// 	ft_strrev(str);
// 	printf("after\n%s", str);    
// 	return (0);
// }

/*DO NOT CONFUSE
char *str_literal = "Hello, World!"; // String literal	NOT CHANGABLE
char str_array[] = "Hello, World!";  // Character array		CHANGABLE
*/
