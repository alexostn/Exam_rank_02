/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
*/
// #include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	rev = 0;
	while (i > 0)
	{
		rev = rev * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (rev);
}

// void	print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char	bit;

// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// }


// int main()
// {
// 	unsigned char octet = (unsigned char)45;
// 	print_bits(octet);
// 	write(1, " ", 1);
// 	octet = reverse_bits(octet);
// 	print_bits(octet);
// }
