#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    char *word;
    struct s_node *next;
    struct s_node *prev;
} t_node;

char *ft_strcpy(char *s1, char *s2, int ammount)
{
    int i = -1;
    while (++i < ammount && s2[i])
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}

t_node *create_node(char *word)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->word = word;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

t_node *ft_split(char *str)
{
    int i = 0;
    int w_begin = 0;
    int w_count = 0;
    t_node *head = NULL;
    t_node *tail = NULL;

    while (str[i])
    {
        while (str[i] <= 32) // skip TABS
            i++;
        if (str[i])
            w_count++; // count words
        while (str[i] > 32) // move index to end of WORD
            i++;
    }

    i = 0; // Reset index for second pass
    while (str[i]) // second pass
    {
        while (str[i] <= 32) // skip TABS
            i++;
        w_begin = i; // i becomes w_begin
        while (str[i] > 32) // move index
            i++;
        if (i > w_begin)
        {
            char *word = (char *)malloc(sizeof(char) * (i - w_begin + 1));
            ft_strcpy(word, &str[w_begin], i - w_begin);
            t_node *new_node = create_node(word);
            if (!new_node)
            {
                // Handle memory allocation failure
                return NULL;
            }
            // Add new_node to the doubly linked list
            if (!head)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }
    }

    return head; // Return the head of the list
}

void free_list(t_node *head)
{
    t_node *current = head;
    while (current)
    {
        t_node *next = current->next;
        free(current->word); // Free the word
        free(current); // Free the node
        current = next;
    }
}

// int main()
// {
//     char *str = 
//     "All movement is accomplished in six stages\n"
//     "And the seventh brings return\n"
//     "The seven is the number of the young light\n"
//     "It forms when darkness is increased by one";

//     // Call ft_split and store the result in a doubly linked list
//     t_node *result = ft_split(str);

//     // Iterate through the doubly linked list and print each word
//     t_node *current = result;
//     int index = 0;
//     while (current)
//     {
//         printf("Word %d: %s\n", index++, current->word); // Print each word with its index
//         current = current->next;
//     }

//     // Free the memory allocated for the doubly linked list
//     free_list(result);
//     return 0;
// }
