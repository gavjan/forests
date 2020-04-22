#include "handler.h"
#include "safe_malloc.h"
#include <stdio.h>
#include <string.h>
// ADD command
static void exec_add(Command command, Trie** t) {
	Trie* node=NULL;
	if(*command.forest!='\0') node=insert_trie(*t, command.forest);
	if(node && !node->child) node->child=new_trie();
	if(node && *command.tree!='\0') node=insert_trie(node->child, command.tree);
	if(node && !node->child) node->child=new_trie();
	if(node && *command.animal!='\0') insert_trie(node->child, command.animal);
	printf("OK\n");
}
// DEL command
static void exec_del(Command command, Trie** t) {
	Trie* node=NULL;
	if(*command.animal!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return;
		node=search_trie(node->child, command.tree);
		if(!node) return;
		delete_trie(node->child, command.animal);
	}
	else if(*command.tree!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return;
		delete_trie(node->child, command.tree);
	}
	else if(*command.forest!='\0')
		delete_trie(*t, command.forest);
	else {
		free_trie(*t);
		*t=new_trie();
	}
}
// PRINT command
static void exec_print(Command command, Trie** t) {
	Trie* node;
	if(*command.tree!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return;
		node=search_trie(node->child, command.tree);
		if(!node) return;
		print_ordered_trie(node->child);
	}
	else if(*command.forest!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return;
		print_ordered_trie(node->child);
	}
	else
		print_ordered_trie(*t);
}
// Check * a
static bool check_rec(Trie* t, char* str) {
	bool ans=false;
	if(t->is_word)
		ans=search_trie(t->child, str);
	for(int i=0; i<t->size; i++)
		if(t->character[i])
			ans=ans || check_rec(t->character[i], str);
	return ans;
}
// Check * * a
static bool check_rec_middle_star(Trie* t, char* str) {
	bool ans=false;
	if(t->is_word)
		ans=check_rec(t->child, str);
	for(int i=0; i<t->size; i++)
		if(t->character[i])
			ans=ans || check_rec_middle_star(
							t->character[i],
							str);
	return ans;
}
// Check * a a
static bool check_rec_left_star(Trie* t, char* tree,
																			 char* animal) {
	bool ans=false;
	if(t->is_word) {
		Trie* node=search_trie(t->child, tree);
		ans=node && search_trie(node->child, animal);
	}
	for(int i=0; i<t->size; i++)
		if(t->character[i])
			ans=ans || check_rec_left_star(
							t->character[i],
							tree, animal);
	return ans;
}
// Check commands with *
static bool check_star(Command command, Trie** t) {
	// CHECK * a
	if(*command.animal=='\0')
		return check_rec(*t, command.tree);
	// CHECK * * a
	if(safe_strcmp(command.forest, "*")==0 &&
		 safe_strcmp(command.tree, "*")==0)
		return check_rec_middle_star(*t, command.animal);
	// CHECK a * a
	if(safe_strcmp(command.tree, "*")==0) {
		Trie* node=search_trie(*t, command.forest);
		return node && check_rec(
						node->child,
						command.animal);
	}
	// CHECK * a a
	if(safe_strcmp(command.forest, "*")==0) {
		return check_rec_left_star(*t, command.tree, command.animal);
	}
	return false;
}
// CHECK command
static bool exec_check(Command command, Trie** t) {
	Trie* node=NULL;
	if(safe_strcmp(command.tree, "*")==0 ||
		 safe_strcmp(command.forest, "*")==0)
		return check_star(command, t);
	if(*command.animal!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return false;
		node=search_trie(node->child, command.tree);
		if(!node) return false;
		node=search_trie(node->child, command.animal);
	}
	else if(*command.tree!='\0') {
		node=search_trie(*t, command.forest);
		if(!node) return false;
		node=search_trie(node->child, command.tree);
	}
	else if(*command.forest!='\0') {
		node=search_trie(*t, command.forest);
	}
	if(node) return node->is_word;
	return false;
}
// CHECK command wrapper
static void exec_check_write(Command command, Trie** t) {
	printf(exec_check(command, t) ? "YES\n" : "NO\n");
}
// DEL command wrapper
static void exec_del_write(Command command, Trie** t) {
	exec_del(command, t);
	printf("OK\n");
}
void handle(Command command, Trie** t) {
	switch(command.type) {
		case ADD:
			exec_add(command, t);
			break;
		case DEL:
			exec_del_write(command, t);
			break;
		case PRINT:
			exec_print(command, t);
			break;
		case CHECK:
			exec_check_write(command, t);
			break;
	}
}
