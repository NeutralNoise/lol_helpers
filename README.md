# lol_helpers

Just some helpful functions that I gathered over the years. They should be commented
with doxygen comments. The only one that isn't is Hash.h. I have also tried to
keep each thing as header only. No real reason for it just felt right you know.

## Examples
If you look in the examples folder you will find some basic examples. Each one is
its own program. Should compile with g++.

For you lazy people here is the commands to compile the examples.

* g++ Hash_main.cpp
* g++ BinaryTree_main.cpp

## Hash.h
This has functions used to hash either a string or combine two numbers into a unique one.

## BinaryTree.h
This has a template structure in it allowing you to put what ever you want into
 a binary search tree. The only real issue with it is that a stack overflow
  happens when the number of elements gets to ~4000.

## Todo
Just some tasks that I would like to get around to doing one day.

1. Comment Hash.h with doxygen comments.
2. Add tree balancing to BinaryTree.
3. Look into BinaryTree stack overflow.
4. Add some other things.
