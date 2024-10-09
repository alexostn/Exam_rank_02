/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
 
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.
 
Examples:
 
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c >= 'A' && c <= 'Z')
				c = 'A' + ('Z' - c);// c = 27 - (c - 'A' + 1) + 'A' - 1; or (27 - letter)
			else if (c >= 'a' && c <= 'z')
				c = 'a' + ('z' - c); // c = 27 - (c - 'a' + 1) + 'a' - 1; or (27 - letter)
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
