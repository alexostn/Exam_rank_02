/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
//0 int start
	// end
	// i
//1 go to the end of string
//OPEN HUGE WHILE CYCLE i <= 0
//2 go backwards SKIP TABS
//3 mark END of the word
//4 SKIP LETTERS
//5 i + 1 mark START of the word
//6 while START <= END for WRITING START++
//7 if flag == 0 write " "
//8 newline, return

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int end;
		int start;
		int i = 0;
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] <= 32)
				i--;
			end = i;
			while (av[1][i] > 32)
				i--;
			start = i + 1;
			int	flag = start;
			while (start <= end)
				write(1, &av[1][start++], 1);
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
