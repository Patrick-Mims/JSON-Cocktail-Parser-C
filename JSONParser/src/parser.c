#include "Parser.h"

// Allocates memory to libcurl in http_request();
struct LIBCURL *alloc_curl_memory()
{
    struct LIBCURL *mem = NULL;

    if ((mem = malloc(sizeof(struct LIBCURL *))) == NULL)
        exit(EXIT_FAILURE);

    return mem;
}

