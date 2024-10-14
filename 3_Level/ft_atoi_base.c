/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
int	is_base(char c, int base)
{
	return((c >= '0' && c <= '0' + base -1)
		||(c >= 'a' && c <= 'f' + base - 11)
		||(c >= 'A' && c <= 'F' + base - 11));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result = 0;
	int	sign = 1;
	//int	i = 0;

	while (*str <= 32)//skip tabs
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-'||*str == '+')
		str++;
	while (*str)
	{
		if (is_base(*str, str_base))// Using the is_in_base function to check if the character belongs to the base
		{
			if (*str >= '0' && *str <= '9')
				result = result * str_base + *str - '0';
			if (*str >= 'a' && *str <= 'f')
				result = result * str_base + *str - 'a' + 10;
			if (*str >= 'A' && *str <= 'F')
				result = result * str_base + *str - 'A' + 10;
		}
		else
			break;
		str++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int main()
// {
// // Examples of strings and their bases

//     printf("ft_atoi_base(\"1A\", 16) = %d\n", ft_atoi_base("1A", 16));    // 26
//     printf("ft_atoi_base(\"10\", 2) = %d\n", ft_atoi_base("10", 2));      // 2
//     printf("ft_atoi_base(\"111\", 2) = %d\n", ft_atoi_base("111", 2));    // 7
//     printf("ft_atoi_base(\"7F\", 16) = %d\n", ft_atoi_base("7F", 16));    // 127
//     printf("ft_atoi_base(\"-1A\", 16) = %d\n", ft_atoi_base("-1A", 16));  // -26
//     printf("ft_atoi_base(\"-100\", 10) = %d\n", ft_atoi_base("-100", 10)); // -100
//     printf("ft_atoi_base(\"12\", 8) = %d\n", ft_atoi_base("12", 8));      // 10
//     printf("ft_atoi_base(\"   101\", 2) = %d\n", ft_atoi_base("   101", 2)); // 5

//     return 0;
// }
