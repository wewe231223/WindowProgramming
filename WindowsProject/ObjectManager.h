#pragma once

#include <Windows.h>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

// ȭ��� �׸� ��� ������Ʈ�� ������ Ŭ����
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