#include "Parser.h"
/*
 * Developer: Patrick Mims
 * Date: March 2, 2025
 */

// a struct to hold the data 
struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

static write_json()
{
    json_object *root = json_object_new_object();

    if(!root)
        exit(EXIT_FAILURE);

    json_object *items = json_object_new_object();
}

/*
     name: async_json_parser()
     purpose: to parse the json file on disk, using json_object
*/
static void parse_json()
{
    struct RATES *rates = NULL;

    if ((rates = malloc(sizeof(struct RATES *))) == NULL)
        exit(EXIT_FAILURE);

    json_object *root = json_object_from_file("data.json");

    puts("parse_json() after json_object");

    if (!root)
    {
        puts("something is wrong");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));

    printf("Version: %s\n", json_c_version());
    printf("Version Number: %d\n", json_c_version_num());
}

// write the data to disk.
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

    return fwrite(dt, size, nmemb, out->stream);
}

// Function Pointer
static size_t (*wb)(char *, size_t, size_t, void *) = write_callback;

char *json_api() // return the api that we're parsing
{
    char *str = NULL;

    if((str = malloc(50 * sizeof(char))) == NULL) exit(EXIT_FAILURE);

    strcpy(str, "https://floatrates.com");
    strcat(str, "/daily");
    strcat(str, "/usd.json");

    return str;
}

// Function Pointer
char *(*api_str)() = json_api;

// Function Pointer
struct LIBCURL *(*acm)() = alloc_curl_memory;

// using libcurl to make the request and call writedata to write to disk.
void *http_request() // This function should not be altered.
{
    printf("-> %s\n", api_str()); // DEBUG

    struct IO io = {
        "data.json",
        NULL
    };

    struct LIBCURL *libcurl = NULL;

    libcurl = acm(); 
    libcurl->curl = curl_easy_init();

    // function: write_callback
    // argument: (struct IO io) &io, for file name.
    curl_easy_setopt(libcurl->curl, CURLOPT_URL, api_str());
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, wb);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, &io);

    if (libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    libcurl->code = curl_easy_perform(libcurl->curl);

    curl_easy_cleanup(libcurl->curl);

    if (CURLE_OK != libcurl->code)
        fprintf(stderr, "curl told us %d\n", libcurl->code);

    curl_global_cleanup();
}

void *(*hr)(void *) = http_request; // function pointer. Unnecessary, but it works.

// Factory fn calls pthread_create method thereby passing the thread and function.
void thread_factory(pthread_t *thread, const void *(*fn)(void *))
{
    void *result;

    int rc = pthread_create(&thread, NULL, fn, NULL);

    if (rc != 0)
        fprintf(stderr, "Error: pthread_create()");

    pthread_join(thread, &result);
}

// begin here
int main(void)
{
    puts("JSON Parser");

    // Define a new pthread object.
    pthread_t usd_thread;

    // Pass thread and the function that uses libcurl for the request.
//    thread_factory(&usd_thread, hr);
    parse_json();

    return 0;
}
