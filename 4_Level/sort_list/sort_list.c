/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}

*/
#include "list.h"    // Include the header file that contains the definition of the t_list structure
#include <stdlib.h>  // Include the standard library for using malloc, free, and other functions

// Function to sort a singly linked list
t_list *sort_list(t_list* lst, int (*cmp)(int, int)) 
    {
    int swap;               // Variable for temporarily storing data during the swap
    t_list *start;         // Pointer to the start of the list for returning

    start = lst;           // Save the pointer to the start of the list

    // The loop continues as long as the current element and the next are not NULL
    while (lst != NULL && lst->next != NULL)
    {
        // If the current elements are not in the correct order
        if ((*cmp)(lst->data, lst->next->data) == 0) // Call the comparison function
        {
            // Swap the data values between the current and next nodes
            swap = lst->data;             // Save the value of the current node
            lst->data = lst->next->data;  // Assign the value of the next node to the current node
            lst->next->data = swap;        // Assign the temporary value to the next node
            
            lst = start;                  // Return to the start of the list to continue sorting
        }
        else
            lst = lst->next;              // Move to the next node if the order is correct
    }

    return (start);                     // Return the pointer to the start of the sorted list
}
