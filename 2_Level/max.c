/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
int max(int *tab, unsigned int len)
{
  int result;
  unsigned int  i = 0;
  if (len == 0)
    return (0);
  result = tab[i];
  while (i < len)
  {
    if (result < tab[i])
      result = tab[i];
    ++i;
  }
  return (result);
}
/*
int	main()
{

		int	tab[] = {1, 9, 6, 8, 4, 10};
		int	len = sizeof(tab) / sizeof(tab[0]);

		int	result = max(tab, len);

		printf("%d", result);
	
	printf("\n");

	return (0);
}
*/
