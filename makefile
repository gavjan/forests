# forests makefile
CC       ?= gcc
CFLAGS   += -Wall -Wextra -std=c11 -O2
OBJS = trie.o stack.o safe_malloc.o parser.o handler.o main.o

all: make

run: make; ./forests

make: $(OBJS)
	$(CC) $(CFLAGS) -o forests main.c trie.c trie.h stack.c stack.h safe_malloc.c safe_malloc.h parser.c parser.h handler.c handler.h

$(OBJS): trie.h stack.h safe_malloc.h parser.h handler.h

valgrind: make; valgrind --error-exitcode=15 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./forests

valgrind_origin: make; valgrind --error-exitcode=15 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -v ./forests

# For testing with binary file 'forests' and tests folder 'tests'
test: make; ./test.sh forests tests

clean:
	-@$(RM) forests *.out *.err *.o
