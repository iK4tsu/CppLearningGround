//~ point.cpp
//~ This file contains the implementation of the functions

#include <iostream>
#include <cmath>

#include <stdio.h>

#include "point.h"

void print(Point2D p) {
  printf("(%.1f, %.1f)", p.x, p.y );
}

Point2D scanPoint()
{
	std::cout << "Enter a point > ";
	Point2D point;
	std::cin >> point.x >> point.y;
	return point;
}

double distanceOf(Point2D& point)
{
	return std::sqrt(std::pow(point.x, 2) + std::pow(point.y, 2));
}
