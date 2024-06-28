#include <iostream>
#include <string>
#include "Point.h"


// Default Point Constructor 
Point::Point() {
	x = 0;
	y = 0;
}

// X and Y param constructor 
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

// Swap the x and y values 
void Point::swapXY() {
	int holder = this->x;
	this->x = this->y;
	this->y = holder;
}

// Set the X and Y values at the same time
void Point::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

