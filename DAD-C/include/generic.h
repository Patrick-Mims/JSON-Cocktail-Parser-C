#ifndef GENERIC_H
#define GENERIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Node 
{
    int data;
    struct Node *next_ptr;
};

struct Node *create_node();
void *create_node();
void *insert(struct Node **, int);

#endif GENERIC_H
