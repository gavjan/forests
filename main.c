// [IPP] Małe Zadanie(Small Task), Gevorg Chobanyan 401929
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "safe_malloc.h"
#include "parser.h"
#include "handler.h"
#include "trie.h"
#include <ctype.h>
// Clear tokens and reset strings
Command clear_tokens(Command command) {
	command.forest=safe_realloc(command.forest, sizeof(char));
	command.tree=safe_realloc(command.tree, sizeof(char));
	command.animal=safe_realloc(command.animal, sizeof(char));
	command.forest[0]='\0';
	command.tree[0]='\0';
	command.animal[0]='\0';
	*command.forest_capacity=STARTING_SIZE;
	*command.tree_capacity=STARTING_SIZE;
	*command.animal_capacity=STARTING_SIZE;
	return command;
}
// Check if line contains white spaces
bool isspace_line(const char* line) {
	int i=0;
	while(line[i]) {
		if(!isspace(line[i])) return false;
		i++;
	}
	return true;
}
int main() {
	size_t forest_capacity, tree_capacity, animal_capacity;
	char* line=NULL;
	Trie* forests=new_trie();
	size_t len=0;
	int line_length;
	Command command={
					UNRECOGNIZED,
					safe_malloc(sizeof(char)),
					safe_malloc(sizeof(char)),
					safe_malloc(sizeof(char)),
					&forest_capacity,
					&tree_capacity,
					&animal_capacity
	};
	while((line_length=getline(&line, &len, stdin))!=-1) {
		command=clear_tokens(command);
		line[--line_length]=0;
		if(line[0]=='#') continue;
		if(isspace_line(line)) continue;
		if(!line) err();
		command=parse_command(line, line_length, command);
		if(command.type==UNRECOGNIZED) err();
		else handle(command, &forests);
	}
	safe_free(command.forest);
	safe_free(command.tree);
	safe_free(command.animal);
	safe_free(line);
	free_trie(forests);
	exit(0);
}
