#pragma once

#include <iostream>
#include <vector>
#include "Point.h"

enum class TetColor {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE_LIGHT,
	BLUE_DARK,
	PURPLE,
};

enum class TetShape {
	S,
	Z,
	L,
	J,
	O,
	I,
	T,
	COUNT,
};

class Tetromino {
	friend class GridTetromino;
private:
	TetColor color;
	TetShape shape;
	std::vector<Point> blockLocs;

public:
	friend class TestSuite;
	Tetromino();
	TetColor getColor() const { return color; };
	TetShape getShape() const { return shape; };
	void setShape(TetShape shape);
	void rotateClockwise();
	void printToConsole() const;
	static TetShape getRandomShape();
};
