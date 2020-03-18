cmake_minimum_required(VERSION 3.15)
project(forests C)

set(CMAKE_C_STANDARD 99)

add_executable(forests main.c trie.c trie.h stack.c stack.h safe_malloc.c safe_malloc.h parser.c parser.h handler.c handler.h)
