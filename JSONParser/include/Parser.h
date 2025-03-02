#ifndef PARSER_H
#define PARSER_H

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIBCURL
{
    CURL *curl;
    CURLcode code;
};

struct QUEUE
{
    char name[10];
    int age;
    int ptr;
    int size;
};

// QUEUE - 
struct QUEUE *new_queue(int); 
// LIBCURL
struct LIBCURL *alloc_curl_memory();
// NODE
void *http_request();
void thread_factory();

#endif
