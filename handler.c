#include "handler.h"
#include <stdio.h>
#include <string.h>
void exec_add(Command command, Trie** t) {
	Trie* node=NULL;
	if(*command.forest!='\0') node=insert_trie(*t,command.forest);
	if(node && !node->child) node->child=new_trie();
	if(node && *command.tree!='\0') node=insert_trie(node->child,command.tree);
	if(node && !node->child) node->child=new_trie();
	if(node && *command.animal!='\0') insert_trie(node->child,command.animal);
	printf("OK\n");
}
void exec_del(Command command, Trie** t) {
	Trie* node=NULL;
	if(*command.animal!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return;
		node=search_trie(node->child,command.tree);
		if(!node) return;
		delete_trie(node->child,command.animal);
	}
	else if(*command.tree!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return;
		delete_trie(node->child,command.tree);
	}
	else if(*command.forest!='\0')
		delete_trie(*t,command.forest);
	else {
		free_trie(*t);
		*t=new_trie();
	}
}
void exec_print(Command command, Trie** t) {
	Trie* node;
	if(*command.tree!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return;
		node=search_trie(node->child,command.tree);
		if(!node) return;
		print_ordered_trie(node->child);
	}
	else if(*command.forest!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return;
		print_ordered_trie(node->child);
	}
	else
		print_ordered_trie(*t);
}
bool check_rec(Trie* t, char* str) {
	bool ans=false;
	if(t->is_word) {
		ans=search_trie(t->child, str);
	}
	for(int i=0; i<CHAR_SIZE; i++)
		if(t->character[i])
			ans=ans || check_rec(t->character[i], str);
	return ans;
}
bool check_star(Command command, Trie** t) {
	if(*command.animal=='\0') // CHECK * a
		return check_rec(*t, command.tree);
}

bool exec_check(Command command, Trie** t) {
	Trie* node=NULL;
	if(strcmp(command.tree,"*")==0 ||
		strcmp(command.forest,"*")==0)
		return check_star(command,t);
	if(*command.animal!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return false;
		node=search_trie(node->child,command.tree);
		if(!node) return false;
		node=search_trie(node->child,command.animal);
	}
	else if(*command.tree!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return false;
		node=search_trie(node->child,command.tree);
	}
	else if(*command.forest!='\0') {
		node=search_trie(*t,command.forest);
	}
	if(node) return node->is_word;
	return false;
}
void exec_check_write(Command command, Trie** t) {
	printf(exec_check(command,t) ? "YES\n": "NO\n");
}
void exec_del_write(Command command, Trie** t) {
	exec_del(command,t);
	printf("OK\n");
}
void handle(Command command, Trie** t) {
	switch(command.type) {
		case ADD:
			exec_add(command,t);
			break;
		case DEL:
			exec_del_write(command, t);
			break;
		case PRINT:
			exec_print(command,t);
			break;
		case CHECK:
			exec_check_write(command, t);
			break;
	}
}
