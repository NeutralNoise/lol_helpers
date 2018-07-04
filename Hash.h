//Bradley Macdonald
//2016
#ifndef HASH_H
#define HASH_H

/**
* \file Hash.h
* \version 1.0
* \author Bradley Macdonald
* \date 2016
*
*  Helper funcations that relate to hashings things
*/

/** \brief Uniquely encodes two natural numbers into a single natural number. Using Cantor pairing function.
*	\param x The first number.
*	\param y The second number.
*	\return The single number.
* \note https://en.wikipedia.org/wiki/Cantor_pairing_function
*/

inline unsigned long long pairing_function(const unsigned long long &x, const unsigned long long &y) {
	return ((x + y)*(x + y + 1) / 2) + y;
}


/** \brief Hashes a string into a number.
*	\param str The string to be hashed
*	\return The hashed string.
* \note http://www.cse.yorku.ca/~oz/hash.html
*/

inline long djb2Hash(char * str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

#endif //HASH_H
