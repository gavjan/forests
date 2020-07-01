CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS	=

.PHONY: all clean

all: forests

forests: main.o trie.o stack.o safe_malloc.o parser.o handler.o
	$(CC) $(LDFLAGS) -o $@ $^
trie.o: src/trie.c src/trie.h src/safe_malloc.h src/stack.h
	$(CC) $(CFLAGS) -c $<
stack.o: src/stack.c src/stack.h src/trie.h src/safe_malloc.h
	$(CC) $(CFLAGS) -c $<
safe_malloc.o: src/safe_malloc.c src/safe_malloc.h src/trie.h src/stack.h
	$(CC) $(CFLAGS) -c $<
parser.o: src/parser.c src/parser.h src/trie.h src/safe_malloc.h
	$(CC) $(CFLAGS) -c $<
handler.o: src/handler.c src/handler.h src/parser.h src/safe_malloc.h
	$(CC) $(CFLAGS) -c $< 
main.o: src/main.c src/parser.h src/handler.h src/trie.h src/safe_malloc.h
	$(CC) $(CFLAGS) -c $<

run: forests
	./$<

valgrind: forests
	valgrind --error-exitcode=15 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./$<

# For testing with binary file 'forests' and tests folder 'tests'.
test: forests test.sh
	./test.sh $< tests

clean:
	-@$(RM) forests *.out *.err *.o vgcore.*
