/*
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
*/
#include <unistd.h>

int	main (int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		while (av[1][i])
		{
			char	c = av[1][i]; //initialize char c inside loop
			if (c >= 'A' && c <= 'Z')
				c = c + 32;
			else if (c >= 'a' && c <= 'z')
				c = c - 32;
			write(1, &c, 1);//write one time only
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
