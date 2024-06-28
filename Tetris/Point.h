#pragma once

#include <iostream>
#include <string>


class Point {
private:
	int x;
	int y;

public:
	friend class TestSuite;
	Point();
	Point(int x, int y);

	int getX() const {
		return this->x;
	}

	int getY() const {
		return this->y;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void setXY(int x, int y);

	void swapXY();

	void multiplyX(int factor) {
		x = x * factor;
	}

	void multiplyY(int factor) {
		y = y * factor;
	}

	std::string toString() const {
		std::string returnString = "[" + std::to_string(this->x) + "," + std::to_string(this->y) + "]";
		return returnString;
	}
};

