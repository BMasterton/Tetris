#include "Gameboard.h"
#include "Point.h"
#include <iomanip>
#include <vector>

// METHODS -------------------------------------------------
	// 
	// constructor - empty() the grid
Gameboard::Gameboard() {
	empty();
};

// fill the board with EMPTY_BLOCK 
//   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))
// - params: none
// - return: nothing
void Gameboard::empty() {
	for (int i = 0; i < Gameboard::MAX_Y; i++) {
		fillRow(i, Gameboard::EMPTY_BLOCK);
	}
};

// print the grid contents to the console (for debugging purposes)
//   use std::setw(2) to space the contents out 
//   (google it, you'll need to #include <iomanip>).
//   If the content == EMPTY_BLOCK, print a '.', otherwise print the content.
// - params: none
// - return: nothing
void Gameboard::printToConsole() const {
	for (int i = 0; i < Gameboard::MAX_Y; i++) {
		for (int j = 0; j < Gameboard::MAX_X; j++) {
			if (Gameboard::grid[i][j] == Gameboard::EMPTY_BLOCK) {
				std::cout << std::setw(2);
				std::cout << '.';
			}
			else {
				std::cout << std::setw(2);
				std::cout << Gameboard::grid[i][j];
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
};

// get the content at a given point 
// assert the point is valid (use isValidPoint())
// - param 1: a Point (the XY of the content weant to retrieve)
// - return: an int, the content from the grid at the specified point 
int Gameboard::getContent(const Point& point) const {
	if (isValidPoint(point)) {
		return (Gameboard::grid[point.getY()][point.getX()]);
	}

	return -1; //not sure what to return if it isnt valid, would it be 0 or -1
};

// get the content at a given XY location
// assert the point is valid (use isValidPoint())
// - param 1: an int for X (column)
// - param 2: an int for Y (row)
// - return: an int, the content from the grid at the specified XY
int Gameboard::getContent(const int columnX, const int rowY) const {
	if (isValidPoint(columnX, rowY)) {
		return (Gameboard::grid[rowY][columnX]);
	}

	return -1; //not sure what to return if it isnt valid, would it be 0 or -1
};

// set the content at a given point (ignore invalid points)
// - param 1: a Point
// - param 2: an int representing the content we want to set at this location.
void Gameboard::setContent(const Point& point, const int contentToSet) {
	if (isValidPoint(point)) {
		Gameboard::grid[point.getY()][point.getX()] = contentToSet;
	}

};

// set the content at an x,y position (ignore invalid points)
// - param 1: an int for X (column)
// - param 2: an int for Y (row)
// - param 3: an int representing the content we want to set at this location	
void Gameboard::setContent(const int columnX, const int rowY, const int contentToSet) { //not 100% sure i can reference a vector like this, might need to address it 
	if (isValidPoint(columnX, rowY)) {
		Gameboard::grid[rowY][columnX] = contentToSet;
	}


};

// set the content for a set of points (ignore invalid points)
// - param 1: a vector of Points representing locations
// - param 2: an int representing the content we want to set.
void Gameboard::setContent(std::vector<Point>& locationPoints, const int contentToSet) {
	for (Point points : locationPoints) {
		if (isValidPoint(points)) {
			Gameboard::grid[points.getY()][points.getX()] = contentToSet;
		}

	}
};

// Determine if (valid) all points passed in are empty
// *** IMPORTANT: Assume invalid x,y values can be passed to this method.
// Invalid meaning outside the bounds of the grid.
// * ONLY TEST VALID POINTS (use isValidPoint()). Ignore invalid Points.
// Using invalid points to index into the grid would cause undefined behaviour. 
// - param 1: a vector of Points representing locations to test
// - return: true if the content at ALL VALID points is EMPTY_BLOCK, false otherwise
bool Gameboard::areAllLocsEmpty(const std::vector<Point> pointTestLocations) const {
	bool validTest = true;
	for (Point point : pointTestLocations) {
		if (isValidPoint(point)) {
			if (Gameboard::grid[point.getY()][point.getX()] != EMPTY_BLOCK) {
				validTest = false;
			}
		}
	}
	return validTest; // TODO CHANGE
};

// Remove all completed rows from the board
//   use getCompletedRowIndices() and removeRows() 
// - params: none
// - return: the count of completed rows removed
int Gameboard::removeCompletedRows() {
	std::vector<int> completedRows = getCompletedRowIndices();
	removeRows(completedRows);


	return completedRows.size();
};

// A getter for the spawn location
// - params: none
// - returns: a Point, representing our private spawnLoc
Point Gameboard::getSpawnLoc() {
	return spawnLoc;
};

// This is commented out to allow us to test. 

   // Determine if a given Point is a valid grid location
   // - param 1: a Point object
   // - return: true if the point is a valid grid location, false otherwise
bool Gameboard::isValidPoint(const Point& point) const {
	int pointX = point.getX();
	int pointY = point.getY();
	//if the x is >= 0 and <less than <= 10, and y is >= 0 and <= 19
	if (pointX >= Gameboard::MIN_X && pointX <= Gameboard::MAX_X && pointY >= Gameboard::MIN_Y && pointY <= Gameboard::MAX_Y) {
		return true;
	}
	return false;
};

// Determine if a given XY is a valid grid location
// - param 1: an int representing x
// - param 2: an int representing y
// - return: true if the x,y is a valid grid location, false otherwise
bool Gameboard::isValidPoint(const int x, const int y) const {
	if (x >= Gameboard::MIN_X && x <= Gameboard::MAX_X && y >= Gameboard::MIN_Y && y <= Gameboard::MAX_Y) {
		return true;
	}
	return false;
};

// return a bool indicating if a given row is full (no EMPTY_BLOCK in the row)
// assert the row index is valid
// - param 1: an int representing the row index we want to test
// - return: bool representing if the row is completed
bool Gameboard::isRowCompleted(const int rowIndexToTest) const {
	if (rowIndexToTest >= Gameboard::MIN_Y && rowIndexToTest <= Gameboard::MAX_Y) {
		for (int i = 0; i < Gameboard::MAX_X; i++) {
			if (Gameboard::grid[rowIndexToTest][i] == Gameboard::EMPTY_BLOCK) {
				return false;
			}
		}
		return true;
	}
	return false;
};

// fill a given grid row with specified content
// - param 1: an int representing a row index
// - param 2: an int representing content
// - return: nothing
void Gameboard::fillRow(const int rowIndex, const int content) {
	for (int i = 0; i < Gameboard::MAX_X; i++) {
		Gameboard::grid[rowIndex][i] = content;
	}
};

// scan the board for completed rows.
// Iterate through grid rows and use isRowCompleted(rowIndex)
// - params: none
// - return: a vector of completed row indices (integers).
std::vector<int> Gameboard::getCompletedRowIndices() const {
	std::vector<int> myVec;

	for (int i = 0; i < Gameboard::MAX_Y; i++) {
		if (isRowCompleted(i)) {
			myVec.push_back(i);
		}
	}
	return myVec;
};

// copy a source row's contents into a target row.
// - param 1: an int representing the source row index
// - param 2: an int representing the target row index
// - return: nothing

void Gameboard::copyRowIntoRow(const int sourceRowIndex, const int targetRowIndex) {
	for (int i = 0; i < Gameboard::MAX_X; i++) {
		Gameboard::grid[targetRowIndex][i] = Gameboard::grid[sourceRowIndex][i];
	}
};

// In gameplay, when a full row is completed (filled with content)
// it gets "removed".  To be exact, the row itself is not removed
// but the content from the row above it is copied into it.
// This continues all the way up the grid until tWhe first row is copied
// into the second row.  Finally, the first row is filled with EMPTY_BLOCK
// Given a row index:
//   1) Assert the row index is valid
//   2) Starting at rowIndex, copy each row above the removed
//     row "one-row-downwards" in the grid.
//     (loop from y=rowIndex-1 down to 0, and copyRowIntoRow(y, y+1)).
//   3) call fillRow() on the first row (and place EMPTY_BLOCKs in it).
// - param 1: an int representing a row index
// - return: nothing
void Gameboard::removeRow(const int rowIndex) {
	if (rowIndex >= Gameboard::MIN_Y && rowIndex <= Gameboard::MAX_Y) {
		for (int i = (rowIndex - 1); i > -1; i--) {
			copyRowIntoRow(i, i + 1);
		}
		fillRow(0, Gameboard::EMPTY_BLOCK);
	}
};

// given a vector of row indices, remove them. 
//   Iterate through the vector, call removeRow() on each row index. 
// - param 1: a vector of integers representing row indices we want to remove
// - return: nothing
void Gameboard::removeRows(const std::vector<int>& rowIndicesToRemove) {
	for (int indice : rowIndicesToRemove) {
		removeRow(indice);
	}
};