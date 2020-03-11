#include "trie.h"
#include "stack.h"
#include "safe_malloc.h"
#include <stdlib.h>
Trie* new_trie() {
	Trie* node=safe_malloc(sizeof(Trie));
	node->is_word=false;
	node->child=NULL;
	for(int i=0; i<=CHAR_SIZE-1; i++)
		node->character[i]=NULL;
	return node;
}
Trie* insert_trie(Trie* curr, char* str) {
	while(*str) {
		if(!curr->character[*str-'!']) {
			curr->character[*str-'!']=new_trie();
		}
		curr=curr->character[*str-'!'];
		str++;
	}
	curr->is_word=true;
	return curr;
}
Trie* search_trie(Trie* head, char* str) {
	if(!head || !str) {return NULL;}
	Trie* curr=head;
	while(*str) {
		curr=curr->character[*str-'!'];
		if(!curr) {return NULL;}
		str++;
	}
	return curr;
}
void free_trie(Trie* t) {
	if(!t) return;
	Stack* s;
	create_stack(&s);
	push_stack(&s, t);
	while(!is_empty_stack(s)) {
		t=pop_stack(&s);
		for(int i=0; i<=CHAR_SIZE-1; i++) {
			if(t->character[i]) {
				push_stack(&s, t->character[i]);
			}
		}
		safe_free(t);
	}
	free_stack(&s);
}
