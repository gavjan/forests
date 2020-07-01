#ifndef FORESTS_STACK_H
#define FORESTS_STACK_H
#include <stdbool.h>
#include "trie.h"

typedef struct Stack {
		struct Trie* val;
		struct Stack* next;
} Stack;

// Create a stack
void create_stack(struct Stack** s);

// Check if the stack is empty
struct Trie* pop_stack(struct Stack** s);

// Add an item to stack, return false if no memory available, true otherwise
void push_stack(struct Stack** s, struct Trie* val);

// Remove an item from stack.
bool is_empty_stack(struct Stack* s);

// Free a Stack
void free_stack(struct Stack** s);

#endif //FORESTS_STACK_H
