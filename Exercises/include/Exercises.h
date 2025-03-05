#ifndef EXERCISES_H
#define EXERCISES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next_ptr;
};

void *new_node();
void display(struct Node *);
void insert(struct Node **, int);

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
void *duplicate(const char *);
int *create_array(int, int);

#endif