#include <iostream>
#include "Point.h"
#include "GridTetromino.h"
#include <vector>

// constructor, initialize gridLoc to 0,0
GridTetromino::GridTetromino() {
	setGridLoc(0, 0);
};

// a getter for the tetromino's location
// - params: none
// - return: a Point (the private member variable gridLoc) 
Point GridTetromino::getGridLoc() const {
	return gridLoc;
};

// a setter for the tetronimo's location 
// - param 1: int x
// - param 2: int y
// return: nothing
void GridTetromino::setGridLoc(const int x, const int y) {
	gridLoc.setXY(x, y);
};

// a setter for the tetromino's location
// param 1: a Point (the new gridLoc)
// return: nothing
void GridTetromino::setGridLoc(const Point& newGridLoc) {
	gridLoc = newGridLoc;
};

// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)
// - param 1: int xOffset, the x offset (distance) to move
// - param 2: int yOffset, the sy offset (distance) to move
// - return: nothing
void GridTetromino::move(const int xOffset, const int yOffset) {
	gridLoc.setXY(gridLoc.getX() + xOffset, gridLoc.getY() + yOffset); // i dont feel like this is right 

};

// Build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// You will need to provide this class access to blockLocs (from the Tetromino class).
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
// params: none:
// return: a vector of Point objects.
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	std::vector<Point> pointVector;

	for (Point loc : Tetromino::blockLocs) { // need to fix 
		pointVector.push_back(Point(gridLoc.getX() + loc.getX(), gridLoc.getY() + loc.getY()));
	}
	return pointVector;

};