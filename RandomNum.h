//Bradley Macdonald
//2016
#ifndef RANDOM_NUM_H
#define RANDOM_NUM_H
#include <time.h>
#ifdef _WIN32
#include <limits.h>
#endif
#ifdef __linux__
#include <climits>
#endif // __linux__
#ifdef __CYGWIN__
#include <limits.h>
#ifndef ULLONG_MAX
#define ULLONG_MAX __LONG_MAX__
#endif
#endif
/**
* \file RandomNum.h
* \version 1.0
* \author Bradley Macdonald
* \date 2016
**
* Deterministic random number generator.
*/

/** \class RandomNum
* \brief Deterministic random number generator
* \author Bradley Macdonald
* \version 1.0
* \date 2016
*/

class RandomNum
{
public:

/** \brief Defualt constructor
*
* \return NOTHING
*/

RandomNum() {
	m_seed = (unsigned long long)time(NULL);
	m_state = m_seed;
}

/** \brief Overloaded constructure
*
* \param seed Number to seed the generator with.
* \return Nothing
*/

RandomNum(const unsigned long long &seed) {
	//If the seed is 0 then we will return 0 each time.
	if (seed == 0) {
		m_seed = (unsigned long long)time(NULL);
	}
  else {
    m_seed = seed;
  }
	m_state = m_seed;
}

~RandomNum() {}

/** \brief Generates a random number
*
* \return Random number between UINT_MAX and 0.
*/

unsigned long long GenerateNumber() {
	m_state ^= (m_state << 13);
	m_state ^= (m_state >> 17);
	m_state ^= (m_state << 5);
	return m_state;
}

/** \brief Generates a random number between low and high
*
* \param low Lowest number to generate.
* \param high Highest number to generate.
* \return A random number between low and high inclusive.
*/

unsigned long long GenerateNumber(const unsigned long long &low, const unsigned long long &high) {
	unsigned long long minVal = (low < high) ? low : high;
	unsigned long long maxVal = (low < high) ? high : low;
  //std::numeric_limits<uint64>::max();
	unsigned long long rtnMath = (maxVal - minVal + 1) * double(GenerateNumber() / double(ULLONG_MAX + 1.0));

	//return minVal + uint64(((maxVal - minVal + 1) * double(GenerateNumber() / double(UINT_MAX + 1.0))));
	return minVal + rtnMath;
}

/** \brief 1 in X chance to be true.
*
* \param chance The chance for it to happen.
* \return True if the One in happened
*/

bool OneIn(const unsigned long long &chance) {
	return (chance <= 1 || GenerateNumber(0, chance - 1) == 0);
}

/** \brief Gets the seed for the generater
*
* \return The seed number given to the generator.
*/

unsigned long long GetSeed() const {
	return m_seed;
}

/** \brief Gets the current state of the generator.
*
* \return The state of the generator. This will be the last number generated.
*/

unsigned long long GetState() const {
	return m_state;
}

/** \brief Sets the seed for the generator to use.
*
* \param seed The number with witch to seed the generator.
*/

void SetSeed(const unsigned long long &seed) {
	m_seed = seed;
	m_state = seed;
}

/** \brief Sets the state of the generator.
*
* \param state The number with witch to set the state too.
*/

void SetState(const unsigned long long &state) {
	m_state = state;
}

private:
unsigned long long m_seed;	//!< The seed used to start the generater. The seed can not be 0.
unsigned long long m_state;	//!< The current state of the generater.

};

//We don't need this anymore
#ifdef __CYGWIN__
#undef ULLONG_MAX
#endif

#endif //RANDOM_NUM_H
