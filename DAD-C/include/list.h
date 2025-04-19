#ifndef LIST_H
#define LIST_H

struct Node 
{
    int data;
    struct Node *next_node;
};

struct Node *create_node();
void *new_node();
void *insert(struct Node **, int);

#endif
