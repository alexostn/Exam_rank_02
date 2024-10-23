/*
THIS IS TEST FILE IS NOT NECCESARY ON EXAM, BUT HELPS TO TEST AND UNDERSTAND LOGIC OF FUNCTION
COMPILE:
cc -o test test.c ft_list_remove_if.c
EXPECTED RESULT:
List before removal:
2 -> 3 -> 2 -> 1 -> NULL
List after removal:
3 -> 1 -> NULL
(AS WE COMPARE TO 2)
*/
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

// Declaration of the ft_list_remove_if function
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// Function to create a new list node
t_list *create_node(void *data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL; // Check for successful memory allocation
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add an element to the start of the list
void add_node(t_list **begin_list, void *data)
{
    t_list *new_node = create_node(data);
    if (new_node != NULL)
    {
        new_node->next = *begin_list;
        *begin_list = new_node;
    }
}

// Function to print the list
void print_list(t_list *list, void (*print_data)(void *))
{
    while (list != NULL)
    {
        print_data(list->data);
        list = list->next;
    }
    printf("NULL\n"); // For convenience in output
}

// Function to print integer data
void print_int(void *data)
{
    printf("%d -> ", *(int *)data);
}

// Function to compare two integers
int int_cmp(void *a, void *b)
{
    if (*(int *)a == *(int *)b)
    {
        return 0; // Если равны
    }
    else
    {
        return 1; // Если не равны
    }
}

// Main test function
int main()
{
    t_list *list = NULL; // Initialize an empty list

    // Add elements to the list
    int a = 1, b = 2, c = 3, d = 2; // Example values
    add_node(&list, &a);
    add_node(&list, &b);
    add_node(&list, &c);
    add_node(&list, &d); // List will be: 2 -> 3 -> 2 -> 1 -> NULL

    printf("List before removal:\n");
    print_list(list, print_int); // Print current list

    // Value to remove (e.g., all elements equal to 2)
    int ref_value = 2;

    // Remove elements from the list
    ft_list_remove_if(&list, &ref_value, int_cmp);

    printf("List after removal:\n");
    print_list(list, print_int); // Print modified list

    // Free remaining memory
    while (list != NULL)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return (0);
}
