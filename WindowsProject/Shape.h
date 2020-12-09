#pragma once

#include <Windows.h>

// 기본 색상 정의
//--------------------------------------------------
#define WHITE RGB(255, 255, 255)
#define BLACK RGB(0, 0, 0)
#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
//--------------------------------------------------

class Shape {
public:
	Shape() = default;
	~Shape() = default;

	virtual void draw() = 0;
};
