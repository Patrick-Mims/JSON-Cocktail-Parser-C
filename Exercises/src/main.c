#include "Exercises.h"

int main()
{
    // cast create_node, because it's a void pointer.
    // struct Node *head = (struct Node *)create_node();

    // exercise 1
    struct Node *(*cn)() = new_node; // using function pointer
    struct Node *head = cn();

    for (int i = 0; i < 20; i++)
    {
        insert(&head, (i * 20));
    }

    display(head);

    // exercise 2
    char *ptr = (char *)duplicate("Computer");
    printf("Church Checkin %s\n", ptr);

    // exercise 3

    int *items = create_array(10, 7);

    for (int i = 0; i < 10; i++)
    {
        printf("--%d\n", items[0]);
    }

    return 0;
}