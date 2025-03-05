#include "Exercises.h"

// generic function
// must cast on the other end
//
void *new_node()
{
    void *node = NULL;

    if ((node = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return node;
}

void insert(struct Node **list, int item)
{
    struct Node *node = (struct Node *)new_node();

    node->data = item;
    node->next_ptr = *list;

    *list = node;

    printf("Item Added: %d\n", item);
}

void display(struct Node *l)
{
    struct Node *node = l;

    for (node; node->next_ptr != NULL; node = node->next_ptr)
    {
        printf("linkedList => %d\n", node->data);
    }
}

/*
    Write a function named duplicate that uses dynamic storage 
    allocation to create a copy of a string. 

    For example, the call

    p = duplicate(str);

    would allocate space for a string of the same length as str,
    copy the contents of str into the new string, and return a
    pointer to it. 

    Have duplicate return a null pointer if the memory allocation fails.
*/

void *duplicate(const char *name)
{
    char *str = NULL;

    if((str = malloc(40 * sizeof(char))) == NULL)
        exit(EXIT_FAILURE);

    strncpy(str, name, sizeof(str));

    return str;
}

/*
    Write the following function:

    int *create_array(int n, int initial_value);

    The function should return a pointer to a dynamically allocated
    int array with n numbers, each of which is initialized to 
    initial_value. 

    The return value should be NULL if the array can't be allocated.
*/

int *create_array(int n, int initial_value)
{
    int *data, i = 0;

    if((data = malloc(n * sizeof(int))) == NULL)
        exit(EXIT_FAILURE);

    for(i; i < n; i++)
    {
        data[i] = initial_value;
    }

    return data;
}
