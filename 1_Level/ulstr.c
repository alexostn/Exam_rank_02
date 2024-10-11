#include <unistd.h>

int	main (int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		while (av[1][i])
		{
			char	c = av[1][i];
			if (c >= 'A' && c <= 'Z')
				c = c + 32;
			else if (c >= 'a' && c <= 'z')
				c = c - 32;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// ALTERNATIVE VERSION
/*
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				write(1, &"abcdefghijklmnopqrstuvwxyz"[av[1][i] - 'A'], 1);  // ARRAY OF ARRAY
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				write(1, &"ABCDEFGHIJKLMNOPQRSTUVWXYZ"[av[1][i] - 'a'], 1);  // ARRAY OF ARRAY
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
