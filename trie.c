#include "trie.h"
#include "stack.h"
#include "safe_malloc.h"
#include <stdio.h>
#include <assert.h>
// Return children count
static inline
int children_count(Trie* t) {
	return t->size;
}
// Get index of pointer for char c
static inline
int get_index(Trie* t, char c) {
	for(int i=0; i<t->size; i++)
		if(t->index[i]==c)
			return i;
	return MISSING;
}
// Insert keeping the sorted order
static inline
int sorted_insert(Trie* t, char c) {
	int i;
	for(i=0; i<t->size; i++)
		if(t->index[i]>c)
			break;
	int r=t->size;
	while(i<r) {
		t->character=push_arr_trie(
						r, t->character[r-1],
						t->character, &t->trie_capacity);
		t->index=push_arr_index(
						r, t->index[r-1],
						t->index, &t->index_capacity);
		r--;
	}
	t->character=push_arr_trie(
					i, new_trie(),
					t->character, &t->trie_capacity);
	t->index=push_arr_index(
					i, c,
					t->index, &t->index_capacity);
	t->size++;
	return i;
}
// Shrink to remove emtpy cell
static inline
void shrink(Trie* t, int del_index) {
	assert(t->character[del_index]==NULL);
	int l=del_index;
	while(l<t->size-1) {
		t->character=push_arr_trie(
						l, t->character[l+1],
						t->character, &t->trie_capacity);
		t->index=push_arr_index(
						l, t->index[l+1],
						t->index, &t->index_capacity);
		l++;
	}
	t->character[t->size-1]=NULL;
	t->index[t->size-1]='\0';
	t->size--;
}
Trie* new_trie() {
	Trie* node=safe_malloc(sizeof(Trie));
	node->is_word=false;
	node->child=NULL;
	node->trie_capacity=STARTING_SIZE;
	node->index_capacity=STARTING_SIZE;
	node->character=safe_malloc(sizeof(Trie*));
	node->index=safe_malloc(sizeof(char));
	node->size=0;
	node->character[0]=NULL;
	node->index[0]='\0';
	return node;
}
Trie* insert_trie(Trie* curr, char* str) {
	if(!curr) return NULL;
	int pos;
	while(*str) {
		if((pos=get_index(curr, *str))==MISSING)
			pos=sorted_insert(curr, *str);
		assert(pos!=MISSING);
		curr=curr->character[pos];
		str++;
	}
	curr->is_word=true;
	return curr;
}
Trie* search_trie(Trie* head, char* str) {
	if(!head || !str) return NULL;
	Trie* curr=head;
	int i;
	while(*str) {
		i=get_index(curr, *str);
		if(i==MISSING) return NULL;
		curr=curr->character[i];
		str++;
	}
	return curr;
}
// Recursively try to print the current word
static inline
void print_rec(Trie* t, size_t pos, char** word,
							 size_t* capacity) {
	if(t->is_word) {
		*word=push_arr(pos, '\0', *word,
									 capacity);
		printf("%s\n", *word);
	}
	for(int i=0; i<t->size; i++) {
		*word=push_arr(pos, t->index[i],
									 *word, capacity);
		print_rec(t->character[i], pos+1,
							word, capacity);

	}
}
void print_ordered_trie(Trie* t) {
	if(!t) return;
	size_t capacity=STARTING_SIZE;
	char* word=safe_malloc(sizeof(char));
	print_rec(t, 0, &word, &capacity);
	word=safe_free(word);
}
Trie* free_trie(Trie* t) {
	if(!t) return NULL;
	Stack* s;
	create_stack(&s);
	push_stack(&s, t);
	while(!is_empty_stack(s)) {
		t=pop_stack(&s);
		for(int i=0; i<t->size; i++)
			push_stack(&s, t->character[i]);
		free_trie(t->child);
		t->index=safe_free(t->index);
		t->character=safe_free(t->character);
		safe_free(t);
	}
	free_stack(&s);
	return NULL;
}
bool delete_trie(Trie* head, char* str) {
	if(!head || !str) return false;
	Trie* highest=head;
	char to_delete=*str;
	Trie* curr=head;
	int i;
	while(*str) {
		i=get_index(curr, *str);
		if(i==MISSING)
			return false;
		if(children_count(curr)>1 ||
		curr->is_word) {
			highest=curr;
			to_delete=*str;
		}
		curr=curr->character[i];
		str++;
	}
	curr->child=free_trie(curr->child);
	curr->is_word=false;
	if(children_count(curr)!=0)
		return true;
	int del_index=get_index(highest, to_delete);
	highest->character[del_index]=
					free_trie(
									highest->character[del_index]);
	shrink(highest, del_index);
	return true;
}
