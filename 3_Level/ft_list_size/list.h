#ifndef FT_LIST_H //It is important to ensure that you do not have multiple definitions, 
# define FT_LIST_H//so using #ifndef, #define, and #endif will help avoid this

typedef struct s_list
{
	struct s_list *next;
	void          *data;
} t_list;

int ft_list_size(t_list *begin_list);

#endif
