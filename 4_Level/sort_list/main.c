#include <stdio.h>
#include <stdlib.h>
#include "list.h" // Ensure this file contains the definition of t_list and other necessary functions

// Example comparison function for sorting in ascending order
int ascending(int a, int b) {
    return (a <= b); // If a is less than or equal to b, return 1 (true), otherwise 0 (false)
}

// Function to create a new node
t_list *create_node(int data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list)); // Allocate memory for a new node
    if (!new_node) return NULL; // Check if memory allocation was successful
    new_node->data = data;      // Assign the value to the data field
    new_node->next = NULL;      // Initially, the pointer to the next element is NULL
    return new_node;            // Return the pointer to the new node
}

// Function to add a node to the end of the list
void append_node(t_list **head, int data) {
    t_list *new_node = create_node(data); // Create a new node
    if (!new_node) return; // Check for memory allocation errors

    if (*head == NULL) {
        *head = new_node; // If the list is empty, the new node becomes the first
        return;
    }

    t_list *current = *head; // Pointer to the current node
    while (current->next != NULL) {
        current = current->next; // Move to the next node
    }
    current->next = new_node; // Add the new node to the end of the list
}

// Function to print the list
void print_list(t_list *head) {
    t_list *current = head; // Pointer to the current node
    while (current != NULL) {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    printf("NULL\n"); // Print NULL at the end
}

int main() {
    t_list *head = NULL; // Pointer to the start of the list
    append_node(&head, 5);  // Add elements to the list
    append_node(&head, 3);
    append_node(&head, 8);
    append_node(&head, 1);

    printf("Original list: ");
    print_list(head); // Print the original list

    head = sort_list(head, ascending); // Sort the list

    printf("Sorted list: ");
    print_list(head); // Print the sorted list

    // Free the allocated memory
    t_list *current = head;
    while (current != NULL) {
        t_list *temp = current;
        current = current->next;
        free(temp); // Free memory for each node
    }

    return 0; // Successful program termination
}
