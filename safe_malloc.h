#ifndef FORESTS_SAFE_MALLOC_H
#define FORESTS_SAFE_MALLOC_H
#include <stdlib.h>
#define STARTING_SIZE 1

// Safe free() wrapper
void* safe_free(void* p);

// Safe malloc() wrapper
extern void* safe_malloc(size_t size);

// Safe realloc() wrapper
extern void* safe_realloc(void* p, size_t size);

// Push into dynamically resized string
char* push_arr(size_t i, char value, char* arr, size_t* capacity);

#endif //FORESTS_SAFE_MALLOC_H
