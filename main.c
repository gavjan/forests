// [IPP] Małe Zadanie(Small Task), Gevorg Chobanyan 401929
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#include "safe_malloc.h"
#include "parser.h"
#include <ctype.h>
Command clear_tokens(Command command) {
	command.forest=safe_realloc(command.forest,sizeof(char));
	command.tree=safe_realloc(command.tree,sizeof(char));
	command.animal=safe_realloc(command.animal,sizeof(char));
	command.forest[0]='\0';
	command.tree[0]='\0';
	command.animal[0]='\0';
	*command.forest_capacity=STARTING_SIZE;
	*command.tree_capacity=STARTING_SIZE;
	*command.animal_capacity=STARTING_SIZE;
}
int main() {
	size_t forest_capacity, tree_capacity, animal_capacity;
	char* line=NULL;
	char* cmd;
	size_t len=0;
	size_t line_length;
	Command command={
					UNRECOGNIZED,
					safe_malloc(sizeof(char)),
					safe_malloc(sizeof(char)),
					safe_malloc(sizeof(char)),
					&forest_capacity,
					&tree_capacity,
					&animal_capacity
	};
	while ((line_length = getline(&line, &len, stdin)) != -1) {
		command=clear_tokens(command);
		line[--line_length]=0;
		if(!line) err(EMPTY_COMMAND);
		command = parseCommand(line, line_length, command);
		printf("Command: %d\n", command.type);
		if(*command.forest!='\0') printf("Forest: %s\n", command.forest);
		if(*command.tree!='\0') printf("Tree: %s\n", command.tree);
		if(*command.animal!='\0') printf("Animal: %s\n", command.animal);
	}
	free(line);
	exit(0);
}