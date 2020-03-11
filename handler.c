#include "handler.h"
#include <stdio.h>
void check_and_print(Trie** t, char* str) {
	printf(search_trie(*t,str) ? "YES\n": "NO\n");
}
void exec_add(Command command, Trie** t) {
	if(*command.forest!='\0') insert_trie(*t,command.forest);
	if(*command.tree!='\0') insert_trie(*t,command.tree);
	if(*command.animal!='\0') insert_trie(*t,command.animal);
}
void exec_del(Command command, Trie** t) {

}
void exec_print(Command command, Trie** t) {

}
void exec_check(Command command, Trie** t) {
	if(*command.animal!='\0') check_and_print(t,command.animal);
	else if(*command.tree!='\0') check_and_print(t,command.tree);
	else if(*command.forest!='\0') check_and_print(t,command.forest);
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
			exec_check(command,t);
			break;
	}
}