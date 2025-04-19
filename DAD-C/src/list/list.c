#include "generic.h"
#include "list.h"

struct Node *create_node()
{
    struct Node *node = NULL;

    if((node = malloc(sizeof(struct Node *))) == NULL)
    {
        printf(stderr, "Error: create_node()");
        exit(EXIT_FAILURE);
    }

    return node;
}

void *new_node()
{
    void *node = NULL;

    if((node = malloc(sizeof(void *))) == NULL)
    {
        printf(stderr, "Error: create_node()");
        exit(EXIT_FAILURE);
    }

    return node;
}

void *insert(struct Node **list, int item)
{
    // struct Node *node = create_node();
    struct Node *node = (struct Node *)new_node();
   
    node->data = item;
    node->next_node = *list;

    *list = node;

    printf("*[ %d added ]\n", item);
}

