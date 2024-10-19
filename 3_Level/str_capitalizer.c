/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/

#include <unistd.h>

void str_capitalize(char *str)
{
	int i = 0;

	// Processing the first character
	while (str[i] <= 32) // Skip spaces and tabs
		i++;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32; // Capitalize the first character
	write(1, &str[i], 1);
	i++;//one step forward DO NOT FORGET!!!

	// Processing the remaining characters
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32; // Convert to lowercase
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] -= 32; // Capitalize the first letter after a space or tab
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			str_capitalize(av[i]);
			write(1, "\n", 1); // Move to a new line after each argument
			i++;
		}
	}
	write(1, "\n", 1); // If there were no arguments, output a new line
	return (0);
}
