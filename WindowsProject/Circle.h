#pragma once 

#include "Point.h"
#include "Shape.h"

class Circle : public Shape {
private:
	HWND hWnd;

	int rad;
	Point center;
public:
	Circle() = delete;
	explicit Circle(HWND, Point, int);

	~Circle();

	virtual void draw() override;
};