#include "nrel.h"

/*
 * A queue is similar to a stack, except that items are added at one end but 
 * removed from the other in a FIFO (first-in, first-out) fashion.
 *
 * Operations on a queue might include:
 *
 * 1. Inserting an item at the end of the queue. 
 * 2. Removing an item from the beginning of the queue.
 * 3. Returning the FIRST item in the queue (without changing the queue).
 * 4. Returning the LAST item in the queue (without changing the queue).
 * 5. Testing whether the queue is empty.
 *
 void insert_node();
 void remove_node();
 void first_node();
 void last_node();
 void is_empty(); */

struct QUEUE *new_queue(int size)
{
    struct QUEUE *queue = NULL;

    if((queue = malloc(sizeof(struct QUEUE *))) == NULL) exit(EXIT_FAILURE);

    if((queue->age = malloc(size * sizeof(int))) == NULL)
    {
        free(queue); // Free stack before exit
        exit(EXIT_FAILURE);
    }

    queue->ptr = 0;
    queue->size = size;

    return queue;
}
