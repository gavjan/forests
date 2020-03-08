#ifndef FORESTS_PARSER_H
#define FORESTS_PARSER_H
#include <stdlib.h>

#define EMPTY_COMMAND 1
#define ERR_DEBUG 1
#define UNRECOGNIZED 0
#define ADD 1
#define DEL 2
#define PRINT 3
#define CHECK 4

// Structure for storing commands
typedef struct command {
		int type;
		char* forest;
		char* tree;
		char* animal;
} Command;
// Function that writes ERROR.
void err(int code);

// Recognize command it into tokens
Command parseCommand(char* line, size_t line_length);

#endif //FORESTS_PARSER_H
