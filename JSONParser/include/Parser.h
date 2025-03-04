#ifndef PARSER_H
#define PARSER_H

#include <curl/curl.h>
#include <json-c/json.h>
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

struct RATES
{
    char *code;
    char *numericCode;
    char *name;
    double rate;
    char *date;
    float inverseRate;
};

// QUEUE -
struct QUEUE *new_queue(int);
// LIBCURL
struct LIBCURL *alloc_curl_memory();
// NODE
void *http_request();
void thread_factory();

static void parse_json();
static void write_json();

#endif
