#pragma once 

#include "Point.h"
#include "ObjectManager.h"

class Circle : public ObjectManager {
private:
	Point center;
	int rad;

	HWND hWnd;
	//COLORREF color;
public:
	Circle();
	explicit Circle(HWND, Point, int);

	~Circle();

	virtual void draw() override;
};