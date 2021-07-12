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

## ByteSwap.h
This is a replacement for the functions used to change endianness. This should just be a drop in replacement for these functions `htons(); htonl(); ntohs(), ntohl`.

## ObjectLoader.h
Used to load dll/so objects and get functions from them.

Note: This might change name at a later data.

## ObjectLoadingHelpers.h
A simple wrapper around windows/linux functions used to load and get functions from dll/so objects.
This is used in ObjectLoader.h. Calls to these functions shouldn't need to be made.

## OSDefines.h
Conatins checks for pre defined things for easy checking if Windows, Linux or Cygwin. Is used ObjectloaderHelpers.h

## Todo
See [TODO.md](TODO.md)

