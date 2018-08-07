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
* g++ RandomNumber_main.cpp
* g++ Distance_main.cpp

## Hash.h
This has functions used to hash either a string or combine two numbers into a unique one.

## BinaryTree.h
This has a template structure in it allowing you to put what ever you want into
 a binary search tree. The CallOnVal functions are likely to stack overflow.

## RandomNum.h
This is an Xorshift number generator. These are easy to make as there is a lot of
 code out there for them. This is pretty handy to have and it beats the c rand() :D.

## Distance.h
This contains two different distance functions. Manhattan Distance and Euclidean
Distance. If you run the example you can see the difference. If you want to see
why this happens have a read [here](https://lyfat.wordpress.com/2012/05/22/euclidean-vs-chebyshev-vs-manhattan-distance/).

## Todo
Just some tasks that I would like to get around to doing one day.

1. Comment Hash.h with doxygen comments.
2. Look into BinaryTree stack overflow. (This is mostly done.)
3. Add some other things.
