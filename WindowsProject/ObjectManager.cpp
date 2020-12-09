#include "ObjectManager.h"

ObjectManager::ObjectManager() : capacity{ 100 }, n_shape{ 0 } {
	shapes = new Shape * [capacity];
}

ObjectManager::~ObjectManager() {
	for (int i = 0; i < n_shape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;
}

void ObjectManager::insert(Shape* shape) {
	if (n_shape == capacity) {
		capacity += 100;
		Shape** temp = new Shape * [capacity];
		memcpy(temp, shapes, n_shape * sizeof(Shape*));
		shapes = temp;
	}
	else {
		shapes[n_shape] = shape;
		n_shape++;
	}
}

void ObjectManager::draw() {
	for (int i = 0; i < n_shape; ++i) {
		shapes[i]->draw();
	}
}
