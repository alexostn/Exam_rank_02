#include <stdio.h>
#include "ft_list.h"

void print_data(void *data)
{
	printf("%s\n", (char *)data);
}

int	main(void)
{
	t_list node4 = {NULL, "Node_4"};
	t_list node3 = {&node4, "Node_3"};
	t_list node2 = {&node3, "Node_2"};
	t_list node1 = {&node2, "Node_1"};

	ft_list_foreach(&node1, print_data);
	return (0);
}
