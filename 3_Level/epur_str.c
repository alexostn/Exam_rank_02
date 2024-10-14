/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	word_started = 0;

	if (ac == 2 && av[1][i] != 0)
	{
		// Skip initial spaces and tabs
		while (av[1][i] <= 32)
			i++;

		while (av[1][i])
		{
			// If the current character is not a space or tab
			if (av[1][i] > 32)
			{
				// If a word has already started, add a space before the next word
				if (word_started)
					write(1, " ", 1);
				word_started = 1;
				// Print the word characters
				while (av[1][i] > 32 && av[1][i] != 0)
				{
					write(1, &av[1][i], 1);
					i++;
				}
			}
			else
				i++; // Skip spaces and tabs between words
		}
	}
	write(1, "\n", 1);
}
