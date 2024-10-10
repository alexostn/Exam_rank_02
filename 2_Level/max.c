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
