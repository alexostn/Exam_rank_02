#include <unistd.h>

void	main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;

		while (av[1][i] != '\0')
		{
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			av[1][i] = av[1][i] + 32;
			write (1, "_", 1);
		}
		write (1, &av[1][i], 1);
		i++;
		}
	}
	write (1, "\n", 1);
}
