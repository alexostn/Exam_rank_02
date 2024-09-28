#include "ft_list.h"

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while(begin_list != (void *)0)// the same as != NULL #include <stdlib.h>
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
