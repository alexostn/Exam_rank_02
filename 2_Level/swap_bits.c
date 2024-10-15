/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/
// #include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return(octet >> 4 | octet << 4);
}

// void print_bits(unsigned char octet) {
//     for(int i = 7; i >= 4; i--) {
//         printf("%d", (octet >> i) & 1);
//     }
//     printf(" | ");
//     for(int i = 3; i >= 0; i--) {
//         printf("%d", (octet >> i) & 1);
//     }
//     printf("\n");
// }

// int main() {
//     unsigned char octet = 65;
//     printf("1 byte\n");
//     printf("_____________\n");
//     print_bits(octet);
//     printf("    \\ /\n");
//     printf("    / \\\n");
//     print_bits(swap_bits(octet));
//     return 0;
// }
