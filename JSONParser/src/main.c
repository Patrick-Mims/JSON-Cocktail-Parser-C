#include "Parser.h"

/*
 *
 * */
void *http_request()
{
    struct IO io = {
        "data.json",
        NULL
    };

    struct LIBCURL *libcurl = NULL;

    libcurl = alloc_curl_memory();
    libcurl->curl = curl_easy_init();

    // function: write_callback
    // argument: (struct IO io) &io, for file name.
    curl_easy_setopt(libcurl->curl, CURLOPT_URL, "https://www.thecocktaildb.com/api/json/v1/1/search.php?f=h");
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, &io);

    if (libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    libcurl->code = curl_easy_perform(libcurl->curl);

    curl_easy_cleanup(libcurl->curl);

    if (CURLE_OK != libcurl->code)
        fprintf(stderr, "curl told us %d\n", libcurl->code);

    curl_global_cleanup();
}

void thread_factory(pthread_t *thread, const void *(*fn)(void *))
{
    void *result;

    int rc = pthread_create(&thread, NULL, fn, NULL);

    if (rc != 0)
        fprintf(stderr, "Error: pthread_create()");

    pthread_join(thread, &result);
}

int main(void)
{
    puts("JSON Parser");

    pthread_t usd_thread;

    thread_factory(&usd_thread, http_request);

    return 0;
}
