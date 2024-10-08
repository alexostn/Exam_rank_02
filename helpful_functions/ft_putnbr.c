#include <unistd.h>

void ft_putnbr(int n)
{
  char digits[] = "0123456789";
  
  if (n >= 10)
    n = n / 10;
  write(1, &digits[n % 10], 1);
}

// FOR 16: (YOU WILL USE IT IN ATOI BASE):

// void	putnbr(int n)
// {
// 	char	*base = "0123456789abcdef";
// 	if (n >= 16)
// 		putnbr(n / 16);
// 	write(1, &base[n % 16], 1);
// }

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int n = atoi(av[1]);
// 		putnbr(n);
// 	}
// 	return (0);
// }
