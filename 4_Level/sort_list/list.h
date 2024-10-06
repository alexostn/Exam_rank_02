// list.h
#ifndef LIST_H
#define LIST_H

typedef struct s_list {
    int data;                  // Field to store integer data in the node
    struct s_list *next;      // Pointer to the next node in the list
} t_list;                      // Typedef for the struct to use t_list instead of struct s_list

// Declaration of the sort_list function
t_list *sort_list(t_list* lst, int (*cmp)(int, int));

#endif // LIST_H
