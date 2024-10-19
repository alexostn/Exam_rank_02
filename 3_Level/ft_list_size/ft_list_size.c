//Iteration approach:
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	
	while (begin_list != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

//Recursive approach:

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}
