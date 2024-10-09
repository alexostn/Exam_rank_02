/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
// #include <limits.h>//OVERFLOW CHECK

int	ft_atoi(const char *str)
{
int  result = 0;
int  sign = 1;

while (*str <= 32)// tabs skip in ASCII
  str++;
if (*str == '-')
  sign = -1;
if (*str == '-' || *str == '+')//only one time, that's why 'if'
  str++;
while (*str >= '0' && *str <= '9')
	{
	result = result * 10 + *str++ - 48;
	// 	// Overflow check
	// if (result * sign > INT_MAX)
	// 	return INT_MAX;
	// if (result * sign < INT_MIN)
	// 	return INT_MIN;
	}
return (result * sign);
}

// #include <stdio.h>

// int  main (int ac, char **av)
// {
//   if (ac == 2)
//   {
//     printf("result %d", ft_atoi(av[1]));
//   }
//   return (0);
// }

/*
EXTENDED CHECK
#include <stdio.h>
#include <limits.h>

int ft_atoi(const char *str); // Declaration of the ft_atoi function

int main(void)
{
    // Test cases for ft_atoi
    const char *test_cases[] = {
        "    42",
        "   -42",
        "42   ",
        "   2147483647", 
        "   -2147483648",
        "   2147483648", 
        "   -2147483649",
        "   0",          
        "   +123",       
        "   +0",         
        "   -0",         
        "   1a2",        
        "   -abc",       
        "   +   ",       
        "   ",           
    };

    // Loop through test cases
    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        int result = ft_atoi(test_cases[i]);
        
        // Check for overflow or underflow
        if (result == INT_MAX)
            printf("Input: \"%s\" => ft_atoi: %d (overflow)\n", test_cases[i], result);
        else if (result == INT_MIN)
            printf("Input: \"%s\" => ft_atoi: %d (underflow)\n", test_cases[i], result);
        else
            printf("Input: \"%s\" => ft_atoi: %d\n", test_cases[i], result);
    }

    return 0;
}
*/
