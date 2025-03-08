#include "nrel.h"

// Allocates memory to libcurl in http_request();
/*
struct LIBCURL *get_curl_memory()
{
    struct LIBCURL *mem = NULL;

    if ((mem = malloc(sizeof(struct LIBCURL *))) == NULL)
        exit(EXIT_FAILURE);

    return mem;
}
*/

// Generic function that requests memory from the heap.
void *get_curl_memory()
{
    void *memory = NULL;

    if ((memory = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return memory;
}