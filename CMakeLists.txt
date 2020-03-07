cmake_minimum_required(VERSION 3.15)
project(forests C)

set(CMAKE_C_STANDARD 99)

add_executable(forests src/main.c src/trie.c src/trie.h)