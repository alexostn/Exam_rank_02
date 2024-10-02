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
int	ft_atoi(const char *str)
{
int  result = 0;
int  sign = 1;

while (*str == ' ' ||(*str >= 9 && *str <= 13))
  str++;
if (*str == '-')
  sign = -1;
if (*str == '-' || *str == '+')//only one time, that's why 'if'
  str++;
while (*str >= '0' && *str <= '9')
    result = result * 10 + *str++ - 48;
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
