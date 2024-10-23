/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/
/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element whose data is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Check that the list is not empty
    if (begin_list == NULL || *begin_list == NULL)
        return;

    // Initialize the pointer cur
    t_list *cur = *begin_list;

    // Compare the data of the current list element with the data to be removed
    if (cmp(cur->data, data_ref) == 0)
    {
        // If the data matches, remove the current element
        *begin_list = cur->next;
        free(cur);
        // Recursively continue processing the remaining part of the list
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        //cur = *begin_list; optional
        // If the data does not match, continue processing the next element
        ft_list_remove_if(&cur->next, data_ref, cmp);//ft_list_remove_if(&(*begin_list)->next, data_ref, cmp); would work as well
    }
}

