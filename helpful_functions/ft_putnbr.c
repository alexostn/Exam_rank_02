#include <unistd.h>

void ft_putnbr(int n)
{
  char digits[] = "0123456789";
  
  if (n >= 10)
    n = n / 10;
  write(1, &digits[n % 10], 1);
}
  
