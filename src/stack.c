#include <stdlib.h>
#include "stack.h"
#include "safe_malloc.h"
void create_stack(Stack** s) {
	*s=NULL;
}
bool is_empty_stack(Stack* s) {
	return s==NULL;
}
void push_stack(Stack** s, Trie* val) {
	Stack* tmp;
	tmp=safe_malloc(sizeof(Stack));
	tmp->next=*s;
	tmp->val=val;
	*s=tmp;
}
Trie* pop_stack(Stack** s) {
	Stack* tmp=*s;
	Trie* val;
	val=(*s)->val;
	*s=(*s)->next;
	safe_free(tmp);
	return (val);
}
void free_stack(Stack** s) {
	while(!is_empty_stack(*s))
		pop_stack(s);
}
