#include "trie.h"
#include "stack.h"
#include "safe_malloc.h"
#include <stdio.h>
#include <stdlib.h>
int children_count(Trie* t) {
	int count=0;
	if(!t) return count;
	for(int i=0;i<CHAR_SIZE;i++)
		if(t->character[i]) count++;
	return count;
}
Trie* new_trie() {
	Trie* node=safe_malloc(sizeof(Trie));
	node->is_word=false;
	node->child=NULL;
	for(int i=0; i<=CHAR_SIZE-1; i++)
		node->character[i]=NULL;
	return node;
}
Trie* insert_trie(Trie* curr, char* str) {
	if(!curr) return NULL;
	while(*str) {
		if(!curr->character[*str-START_CHAR]) {
			curr->character[*str-START_CHAR]=new_trie();
		}
		curr=curr->character[*str-START_CHAR];
		str++;
	}
	curr->is_word=true;
	return curr;
}
Trie* search_trie(Trie* head, char* str) {
	if(!head || !str) return NULL;
	Trie* curr=head;
	while(*str) {
		curr=curr->character[*str-START_CHAR];
		if(!curr) return NULL;
		str++;
	}
	return curr;
}
void print_rec(Trie* t, size_t pos,char** word,
				size_t* capacity) {
	if(t->is_word) {
		*word=pushArr(pos,'\0',*word,capacity);
		printf("%s\n",*word);
	}
	for(int i=0; i<CHAR_SIZE; i++) {
		if(t->character[i]) {
			*word=pushArr(pos, START_CHAR+i, *word, capacity);
			print_rec(t->character[i],pos+1,word,capacity);
		}
	}
}
void print_ordered_trie(Trie* t) {
	if(!t) return;
	size_t capacity=STARTING_SIZE;
	char* word=safe_malloc(sizeof(char));
	print_rec(t,0,&word,&capacity);
	word=safe_free(word);
}
Trie* free_trie(Trie* t) {
	if(!t) return NULL;
	Stack* s;
	create_stack(&s);
	push_stack(&s, t);
	while(!is_empty_stack(s)) {
		t=pop_stack(&s);
		for(int i=0; i<=CHAR_SIZE-1; i++)
			if(t->character[i])
				push_stack(&s, t->character[i]);
		free_trie(t->child);
		safe_free(t);
	}
	free_stack(&s);
	return NULL;
}
bool delete_trie(Trie* head, char* str) {
	if(!head || !str) return false;
	Trie* highest=head;
	char to_delete=(char)(*str-START_CHAR);
	Trie* curr=head;
	while(*str) {
		if(!curr->character[*str-START_CHAR]) return false;
		if(children_count(curr)>1 || curr->is_word) {
			highest=curr;
			to_delete=(char)(*str-START_CHAR);
		}
		curr=curr->character[*str-START_CHAR];
		str++;			
	}
	curr->child=free_trie(curr->child);
	curr->is_word=false;
	if(children_count(curr)!=0)
		return true;

	highest->character[to_delete]=
					free_trie(highest->character[to_delete]);
	return true;
}
