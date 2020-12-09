#pragma once

#include "ObjectManager.h"
#include "Point.h"

class Line : public ObjectManager {
private:
	Point begin, end;
public:
	Line() = delete;
	Line(Point, Point);

	~Line();

	virtual void draw() override;
};