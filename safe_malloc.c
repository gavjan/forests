#include "safe_malloc.h"
#include <stdlib.h>

void* safe_malloc(size_t size) {
	void* result=malloc(size);
	if(!result)
		exit(1);
	return result;
}

void* safe_realloc(void* p, size_t size) {
	void* reallocated=realloc(p, size);
	if(!reallocated) {
		free(p);
		exit(1);
	}
	return reallocated;
}