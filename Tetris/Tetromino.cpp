#include <iostream>
#include <vector>
#include "Tetromino.h"
#include <algorithm>

Tetromino::Tetromino() {
	setShape(TetShape::S);
}

void Tetromino::setShape(TetShape shape) {
	this->shape = shape;
	if (this->shape == TetShape::S) { // red  
		blockLocs = { Point(0,0), Point(0,1), Point(1,1), Point(-1,0) };;
		color = TetColor::RED;
	}
	else if (this->shape == TetShape::Z) { // green
		blockLocs = { Point(0,0), Point(0,1), Point(1,0), Point(-1,1) };
		color = TetColor::GREEN;
	}
	else if (this->shape == TetShape::L) { // orange
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(1,-1) };
		color = TetColor::ORANGE;
	}
	else if (this->shape == TetShape::J) { // dark blue
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(-1,-1) };
		color = TetColor::BLUE_DARK;
	}
	else if (this->shape == TetShape::O) { // yellow
		blockLocs = { Point(0,0), Point(0,1), Point(1,0), Point(1,1) };
		color = TetColor::YELLOW;
	}
	else if (this->shape == TetShape::I) { // light blue
		blockLocs = { Point(0,0), Point(0,1), Point(0,2), Point(0,-1) };
		color = TetColor::BLUE_LIGHT;
	}
	else if (this->shape == TetShape::T) { // purple 
		blockLocs = { Point(0, 0), Point(1, 0), Point(-1, 0), Point(0, -1) };
		color = TetColor::PURPLE;
	}
};


void Tetromino::printToConsole() const {
	// starting point is 3,-3 
	for (int i = 3; i > -4; i--) { // rows or y values
		for (int j = -3; j < 4; j++) { // columns or x values 
			bool pointFound = false;
			for (int k = 0; k < Tetromino::blockLocs.size(); k++) {
				if (Tetromino::blockLocs[k].getY() == i && Tetromino::blockLocs[k].getX() == j) { // if at that position if there is an x and y then show an x at that coord
					pointFound = true;
					break; // if we find a point then we break out of here and print either the X or .
				}
			}
			std::cout << (pointFound ? 'x' : '.'); // if the pointFound is true then we print X and if not we print .
		}
		std::cout << '\n';
	}
	std::cout << '\n';
};


void Tetromino::rotateClockwise() {
	if (Tetromino::shape != TetShape::O) {
		for (int i = 0; i < Tetromino::blockLocs.size(); i++) {
			//relatioship between y and x is: y = -x and x = y
			blockLocs[i].multiplyX(-1);
			blockLocs[i].swapXY();
		}
	}
};

TetShape Tetromino::getRandomShape() {
	//int count = static_cast<int>(TetShape::COUNT);
	//int random = rand() % count;

	return static_cast<TetShape>(rand() % static_cast<int>(TetShape::COUNT));


};
