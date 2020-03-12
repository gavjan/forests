#include "parser.h"
#include "safe_malloc.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
void err() {
	fprintf(stderr, "ERROR\n");
}
char* pushArr(int i, char value, char* arr, size_t* capacity) {
	if(i>(*capacity)-1) {
		*capacity*=2;
		arr=safe_realloc(arr, sizeof(char)*(*capacity));
	}
	if(arr) arr[i]=value;
	return arr;
}
bool startsWith(const char* pre, const char* str) {
	size_t lenpre=strlen(pre), lenstr=strlen(str);
	return lenstr<lenpre ? false : memcmp(pre, str, lenpre)==0;
}
bool is_proper_char(int c) {
	return 33<=c && c<=255;
}
bool get_next_token(const char* line, size_t* start, char** token, size_t* capacity) {
	while(isspace(line[*start])) (*start)++;
	size_t pos=0;
	while(!isspace(line[*start]) && line[*start]!='\0') {
		if(!is_proper_char(line[*start])) return false;
		*token=pushArr(pos,line[*start],*token,capacity);
		(*start)++;
		pos++;
	}
	*token=pushArr(pos,'\0',*token,capacity);
	return pos!=0;
}
int checkFirstWord(const char* line, size_t line_length, int* first_word_length) {
	if(line_length<MIN_COMMAND_LENGTH) return UNRECOGNIZED;
	if(startsWith("ADD", line)) {*first_word_length=ADD_LENGTH; return ADD;}
	if(startsWith("DEL", line)) {*first_word_length=DEL_LENGTH; return DEL;}
	if(startsWith("PRINT", line)) {*first_word_length=PRINT_LENGTH; return PRINT;}
	if(startsWith("CHECK", line)) {*first_word_length=CHECK_LENGTH; return CHECK;}
	return UNRECOGNIZED;
}
Command parseCommand(char* line, size_t line_length, Command command) {
	int first_word_length=0;
	command.type=checkFirstWord(line, line_length, &first_word_length);
	if(line[first_word_length]=='\0' && (command.type==DEL || command.type==PRINT))
		return command;
	size_t start=first_word_length;
	if(isspace(line[start])) {
		if(!get_next_token(line, &start, &command.forest, command.forest_capacity)) {command.type=UNRECOGNIZED; return command;}
		if(line[start]=='\0') {
			return command;
		}
		if(!get_next_token(line, &start, &command.tree, command.tree_capacity)) {command.type=UNRECOGNIZED; return command;}
		if(line[start]=='\0') {
			return command;
		}
		if(!get_next_token(line, &start, &command.animal, command.animal_capacity)) {command.type=UNRECOGNIZED; return command;}
		if(line[start]=='\0') return command;
	}
	command.type = UNRECOGNIZED;
	return command;
}
