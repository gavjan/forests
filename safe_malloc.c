#include "safe_malloc.h"
#include <stdlib.h>
void* safe_free(void* p) {
	if(p) free(p);
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
char* push_arr(size_t i, char value, char* arr, size_t* capacity) {
	if(i>(*capacity)-1) {
		*capacity*=2;
		arr=safe_realloc(arr, sizeof(char)*(*capacity));
	}
	if(arr) arr[i]=value;
	return arr;
}
char* push_arr_index(uint8_t i, char value, char* arr, uint8_t * capacity) {
	if(i>(*capacity)-1) {
		*capacity*=3;
		arr=safe_realloc(arr, sizeof(char)*(*capacity));
	}
	if(arr) arr[i]=value;
	return arr;
}

Trie** push_arr_trie(uint8_t i, Trie* value, Trie** arr, uint8_t* capacity) {
	if(i>(*capacity)-1) {
		*capacity*=3;
		arr=safe_realloc(arr, sizeof(Trie*)*(*capacity));
	}
	if(arr) arr[i]=value;
	return arr;
}