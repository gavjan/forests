#include "safe_malloc.h"
#include <stdlib.h>
void* safe_free(void* p) {
	if(p!=NULL) free(p);
	return NULL;
}
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
char* pushArr(int i, char value, char* arr, size_t* capacity) {
	if(i>(*capacity)-1) {
		*capacity*=2;
		arr=safe_realloc(arr, sizeof(char)*(*capacity));
	}
	if(arr) arr[i]=value;
	return arr;
}