#include "Parser.h"

struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

/*
 *
 * */
static size_t write_callback(char *(*dt)(), size_t size, size_t nmemb, void *stream)
{   
    // cast the void pointer to struct IO
    struct IO *out = (struct IO *)stream;

    if (!out->stream)
    {
        out->stream = fopen(out->json_file, "wb");

        if (!out->stream)
            return 0;
    }

    // return fwrite(dt, size, nmemb, out->stream);
    return fwrite(dt, size, nmemb, out->stream);
}

char *json_api()
{
    char *str = (char *)malloc(50 * sizeof(char));

    strcpy(str, "https://floatrates.com");
    strcat(str, "/daily");
    strcat(str, "/usd.json");

    return str;
}

char *(*str_api)() = json_api; // function pointer

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
    curl_easy_setopt(libcurl->curl, CURLOPT_URL, str_api());
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

void *(*hr)() = http_request; // function pointer

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

    thread_factory(&usd_thread, hr);

    return 0;
}
