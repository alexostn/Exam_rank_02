/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
  */
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int j;
		char letter;

		while (av[1][i])
		{
			letter = av[1][i];
			j = 0;

			// Handling lowercase letters
			if (letter >= 'a' && letter <= 'z')
			{
				while (j < (letter - 'a' + 1))
				{
					write(1, &letter, 1);
					j++;
				}
			}
			// Handling uppercase letters
			else if (letter >= 'A' && letter <= 'Z')
			{
				while (j < (letter - 'A' + 1))
				{
					write(1, &letter, 1);
					j++;
				}
			}
			// Handling non-letter characters
			else
			{
				write(1, &letter, 1); // Print the symbol as it is, without repetition
			}
			i++;
		}
	}
	return (0);
}
