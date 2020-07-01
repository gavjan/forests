# Forests
## Description

There are forests. In each forest there are trees. On each tree there are animals.

The program reads data from the standard input and executes the commands described below.

* `ADD forest` - Adds a forest.
* `ADD forest tree` - Adds forest and tree in the forest.
* `ADD forest tree animal` - Adds forest, tree in the forest and animal living on this tree.

The `ADD` command only adds those entities that are missing. Attempts to add an existing entity in the world again are ignored.

* `DEL` - Removes all forests, all trees in them and all animals living on them.
* `DEL las` - Removes a forest, all trees in it and all animals living on them.
* `DEL forest tree` - Remove the tree in the given forest and all animals living on that tree.
* `DEL forest tree animal` - Remove the animal living on the given tree in the given forest.

The `DEL` command only removes entities that exist. Attempts to remove a non-existent entity are ignored.

* `PRINT` - Prints all forests.
* `PRINT forest` - Prints all trees in the given forest.
* `PRINT forest tree` - Lists all animals living on the given tree in the given forest.

The `PRINT` command prints the names of entities lexicographically sorted in ascending order, each name on a separate line.

* `CHECK forest` - Checks if there is a forest with the given name.
* `CHECK forest tree` - Checks if there is a tree with the given name in the given forest.
* `CHECK forest tree animal` - Checks if the given animal lives on the given tree in the given forest.

In the `CHECK` command, you can specify an asterisk (`*`) as the parameter value except the last one. The asterisk is a metacharacter that matches any name.

----------------------
## Compile

To build and run the executable `forests`:
```
make run
```
To run with valgrind enabled:
```
make valgrind
```
To check against all the tests located in the directory `tests`:
```
make test
```

## Tests
As the tests take up too much space in the repo, they are available [here.](https://github.com/gavjan/forests/releases/tag/tests)
