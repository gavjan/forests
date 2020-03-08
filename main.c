// [IPP] Małe Zadanie(Small Task), Gevorg Chobanyan 401929
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#include "safe_malloc.h"
#include "parser.h"
#include <ctype.h>
int main() {
	char* line=NULL;
	char* cmd;
	size_t len=0;
	size_t line_length;
	Command command;
	while ((line_length = getline(&line, &len, stdin)) != -1) {
		line[--line_length]=0;
		if(!line) err(EMPTY_COMMAND);
		command = parseCommand(line, line_length);

	}

	free(line);
	exit(0);
}