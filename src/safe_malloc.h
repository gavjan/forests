#ifndef FORESTS_SAFE_MALLOC_H
#define FORESTS_SAFE_MALLOC_H
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#define STARTING_SIZE 1

// Safe free() wrapper
void* safe_free(void* p);

// Safe malloc() wrapper
extern void* safe_malloc(size_t size);

// Safe realloc() wrapper
extern void* safe_realloc(void* p, size_t size);

// Push into dynamically resized string
char* push_arr(size_t i, char value, char* arr, size_t* capacity);

// Safe strcmp() wrapper
int safe_strcmp(const char *s1, const char *s2);

// Push into dynamically resized index array
char* push_arr_index(uint8_t i, char value, char* arr, uint8_t* capacity);

// Push into dynamically resized pointer array
Trie** push_arr_trie(uint8_t i, Trie* value, Trie** arr, uint8_t* capacity);

#endif //FORESTS_SAFE_MALLOC_H
