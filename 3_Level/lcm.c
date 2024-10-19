/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/
int	gcd(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int	temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int    lcm(unsigned int a, unsigned int b)
 {
	unsigned int	res = a * b / gcd(a, b);
	return(res);
 }

// #include <stdio.h>
// #include <stdlib.h>

//  int main(int ac, char **av)
//  {
// 	if (ac == 3)
// 	{
// 	unsigned int	a = atoi(av[1]);
// 	unsigned int	b = atoi(av[2]);

// 	unsigned int	res = lcm (a, b);
// 	printf("%u", res);
// 	}
// 	return (0);
//  }

/*BRUTE FORCE METHOD*/
unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return(0);
	unsigned int	n;
	if (a > b)
		n = a;
	else
		n = b;
while (1) // endless loop
{
	if (n % a == 0 && n % b == 0) // condition to exit the loop when n is divisible by both a and b
		return (n);
	++n; // increment n to check the next potential common multiple
}
