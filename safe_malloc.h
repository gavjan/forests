#ifndef FORESTS_SAFE_MALLOC_H
#define FORESTS_SAFE_MALLOC_H
#include <stdlib.h>

// Safe free() wrapper
void* safe_free(void* p);
// Safe malloc() wrapper
extern void* safe_malloc(size_t size);
// Safe realloc() wrapper
extern void* safe_realloc(void* p, size_t size);

#endif //FORESTS_SAFE_MALLOC_H
