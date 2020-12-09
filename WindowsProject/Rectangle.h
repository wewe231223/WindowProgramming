#pragma once

#include "Shape.h"
#include "Point.h"

class Rect : public Shape {
private:
	Point p1, p2;

	HWND hWnd;
public:
	Rect() = delete;

	Rect(HWND, Point, Point);

	~Rect();

	virtual void draw() override;
};