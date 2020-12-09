#pragma once

// 좌표관리 클래스
struct Point {
// 멤버 변수
	int x, y;

// 생성자및 소멸자
	Point();
	explicit Point(int, int);

	~Point();
};