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

struct LIBCURL *alloc_curl_memory();
void *http_request();
void thread_factory();

#endif
