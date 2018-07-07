//Bradley Macdonald
//2018
#ifndef DISTANCE_H
#define DISTANCE_H
#include <stdlib.h>
#include <math.h>

//I pulled these from different places and just put them in this one file :D.

/**
* \file Distance.h
* \version 1.0
* \author Bradley Macdonald
* \date 2018
*
*  Functions used to find the distance between to points.
*/

/** \brief Finds the distance between two points using manhattan distance.
*	\param x The x position of the first point.
*	\param y The y position of the first point.
*	\param x2 The x position of the second point.
*	\param y2 The y position of the second point.
*	\return The distance between the two points as an int.
*/

inline int ManhattanDistance(const int &x, const int &y, const int &x2, const int &y2) {
  return std::abs(x - x2) + std::abs(y - y2);
}

/** \brief Finds the distance between two points using euclidean distance.
*	\param x The x position of the first point.
*	\param y The y position of the first point.
*	\param x2 The x position of the second point.
*	\param y2 The y position of the second point.
*	\return The distance between the two points as an int.
*/

inline int EuclideanDistance(const int &x, const int &y, const int &x2, const int &y2) {
  return sqrt(((y-y2) * (y - y2)) + ((x - x2) * (x - x2)));
}


#endif //DISTANCE_H
