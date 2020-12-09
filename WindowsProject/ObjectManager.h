#pragma once

#include <Windows.h>

// 기본 색상 정의
//--------------------------------------------------
#define WHITE RGB(255, 255, 255)
#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define BLACK RGB(0, 0, 0)
//--------------------------------------------------

// 화면상에 그릴 모든 오브젝트를 관리할 클래스
class ObjectManager {
public:
	explicit ObjectManager();

	virtual ~ObjectManager();

	virtual void draw() = 0;
};