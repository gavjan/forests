#ifndef FORESTS_TRIE_H
#define FORESTS_TRIE_H
#define MISSING (-1)
#include <stdbool.h>
#include <stdint-gcc.h>

typedef struct Trie {
		char* index;
		struct Trie** character;
		struct Trie* child;
		bool is_word;
		uint8_t trie_capacity;
		uint8_t index_capacity;
		uint8_t size;
} Trie; // A Trie node

// Function that returns a new Trie node
Trie* new_trie();

// Insert a word in to the Trie.
Trie* insert_trie(Trie* curr, char* str);

// Check if a word is in the Trie; If yes return pointer to the last character NULL otherwise
Trie* search_trie(Trie* head, char* str);

// Print all words inside Trie in lexicographical order
void print_ordered_trie(Trie* head);

// Free Trie Node, return false if no memory available, true otherwise
Trie* free_trie(Trie* t);

// Delete a word from Trie
bool delete_trie(Trie* head, char* str);

#endif //FORESTS_TRIE_H
