#pragma once

#include <Windows.h>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

// 화면상에 그릴 모든 오브젝트를 관리할 클래스
class ObjectManager {
private:
	Shape** shapes;
	size_t capacity;
	size_t n_shape;
public:
	ObjectManager();
	~ObjectManager();

	void insert(Shape*);
	void draw();
};