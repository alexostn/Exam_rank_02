//SIMPLIFIED VERSION FOR EXAM
#include <stdlib.h>

char    **ft_split(char *str)
{
	char **arr = malloc(sizeof(char *) * 10000000);
	int	i = 0;

	//skip spaces
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))//!!!works only with this precise writing
		i++;
	int	x = 0;
	int	y = 0;
	while (str[i])
	{
		if (arr[x] == NULL)
			arr[x] = malloc(sizeof(char) * 1000000);
		arr[x][y] = str[i];
		y++;
		i++;
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))//!!!works only with this precise writing
		{
			arr[x][y] = '\0';
			x++;
			y = 0;
			//skip spaces
			while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))//works only with this precise writing
				i++;
		}
	}
	arr[x] = NULL;
	return (arr);
}

// #include <stdio.h>

// int	main()
// {
// 	char **arr = ft_split("All movement is accomplished in six stages\n"
// 	"And the seventh brings return\n"
// 	"The seven is the number of the young light\n"
// 	"It forms when darkness is increased by one");
// 	for (int i = 0; arr[i]; i++)
// 	{
// 		printf("%s %d\n", arr[i], i);
// 		free(arr[i]);
// 	}
// 	free(arr);
// }
