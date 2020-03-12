#include "handler.h"
#include <stdio.h>
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
	printf("OK\n");
}
void exec_print(Command command, Trie** t) {

}
bool exec_check(Command command, Trie** t) {
	Trie* node=NULL;
	if(*command.animal!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return false;
		node=search_trie(node->child,command.tree);
		if(!node) return false;
		node=search_trie(node->child,command.animal);
		return node && node->is_word;
	}
	else if(*command.tree!='\0') {
		node=search_trie(*t,command.forest);
		if(!node) return false;
		node=search_trie(node->child,command.tree);
		return node && node->is_word;
	}
	else if(*command.forest!='\0') {
		node=search_trie(*t,command.forest);
		return node && node->is_word;
	}
	return false;
}
void exec_check_print(Command command, Trie** t) {
	printf(exec_check(command,t) ? "YES\n": "NO\n");
}
void handle(Command command, Trie** t) {
	switch(command.type) {
		case ADD:
			exec_add(command,t);
			break;
		case DEL:
			exec_del(command,t);
			break;
		case PRINT:
			exec_print(command,t);
			break;
		case CHECK:
			exec_check_print(command,t);
			break;
	}
}