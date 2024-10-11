/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/
#include <unistd.h>

// Function to convert a string to an integer
int	ft_atoi(char *str)
{
	int	result; // Variable to store the result
	int	sign;   // Variable to store the sign of the number (in this case, it is always positive)

	result = 0;
	sign = 1;  // Default sign is positive
	// Skip spaces and control characters
	while (*str <= 32)
		str++;
	if (*str == '-')
		sign = -1;
	// Skip the '+' sign if it exists
	if (*str == '+' || *str == '-')
		str++;
	// While the characters are digits, convert them to a number
	while (*str >= '0' && *str <= '9')
	{
		// Increase the value of the number: multiply by 10 and add the current digit
		result = result * 10 + *str - '0';
		str++;
	}
	// Return the result multiplied by the sign (in this case, the sign is always +1)
	return (sign * result);
}

// Function to output a single character
#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

// Main function of the program
int	main(int argc, char *argv[])
{
	int	i;    // Counter for the loop
	int	nbr;  // Variable to store the number passed in the argument

	// If the number of arguments is not equal to 2, just output a new line
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		i = 1; // Start the loop from 1
		nbr = ft_atoi(argv[1]); // Convert the command line argument to a number
		// Loop to output the multiplication table, from 1 to 9
		while (i <= 9 && nbr <= 238609183) // Check that nbr is <= 238609183 (MAX_INT / 9) to avoid overflow
		{
			ft_putnbr(i);           // Output the current value of i (the multiplier)
			write(1, " x ", 3);      // Output the characters " x "
			ft_putnbr(nbr);          // Output the number passed in the argument
			write(1, " = ", 3);      // Output the characters " = "
			ft_putnbr(i * nbr);      // Output the result of the multiplication
			write(1, "\n", 1);       // Output a new line
			i++;                  // Increment the value of i
		}
	}
	return (0); // End the program execution
}
