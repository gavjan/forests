CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS	=

.PHONY: all clean

all: forests

forests: main.o trie.o stack.o safe_malloc.o parser.o handler.o
	$(CC) $(LDFLAGS) -o $@ $^
trie.o: trie.c trie.h safe_malloc.h stack.h
	$(CC) $(CFLAGS) -c $<
stack.o: stack.c stack.h trie.h safe_malloc.h
	$(CC) $(CFLAGS) -c $<
safe_malloc.o: safe_malloc.c safe_malloc.h trie.h stack.h
	$(CC) $(CFLAGS) -c $<
parser.o: parser.c parser.h trie.h safe_malloc.h
	$(CC) $(CFLAGS) -c $<
handler.o: handler.c handler.h parser.h
	$(CC) $(CFLAGS) -c $< 
main.o: main.c parser.h handler.h trie.h safe_malloc.h
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
