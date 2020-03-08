#include "parser.h"
#include <stdio.h>

void err(int code) {
	if(ERR_DEBUG) fprintf(stderr, "ERROR %d\n", code);
	else fprintf(stderr, "ERROR\n");
} //Error code was useful when determining what caused the error

Command parseCommand(char* line, size_t line_length) {
	int firstWordLength=0;


}
