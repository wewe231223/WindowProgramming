#pragma once

#include "ObjectManager.h"
#include "Point.h"

class Rect : public ObjectManager {
private:
	Point p1, p2;

	HWND hWnd;
public:
	Rect();

	Rect(HWND, Point, Point);

	~Rect();

	virtual void draw() override;
};