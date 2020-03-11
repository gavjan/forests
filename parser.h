#ifndef FORESTS_PARSER_H
#define FORESTS_PARSER_H
#include <stdlib.h>
#define UNRECOGNIZED 0
#define ADD 1
#define DEL 2
#define PRINT 3
#define CHECK 4
#define MIN_COMMAND_LENGTH 3
#define ADD_LENGTH 3
#define DEL_LENGTH 3
#define PRINT_LENGTH 5
#define CHECK_LENGTH 5
#define STARTING_SIZE 1

// Structure for storing commands
typedef struct command {
		int type;
		char* forest;
		char* tree;
		char* animal;
		size_t* forest_capacity;
		size_t* tree_capacity;
		size_t* animal_capacity;
} Command;

// Function that writes ERROR.
void err();

// Recognize command it into tokens
Command parseCommand(char* line, size_t line_length, Command command);

#endif //FORESTS_PARSER_H
