#include "Rectangle.h"

Rect::Rect() {}

Rect::Rect(HWND hWnd, Point p1, Point p2) : hWnd{ hWnd }, p1{ p1 }, p2{ p2 } {}

Rect::~Rect() {}

void Rect::draw() {
	// 현재 윈도우의 DC값을 받아옴
	HDC h_dc = GetDC(hWnd);


	//----------------------------------------
	// 파란색으로 채워지는 BRUSH 객체 생성
	HBRUSH h_brush = CreateSolidBrush(BLUE);
	// DC에 생성한 BRUSH 객체를 저장하고
	// 기존에 사용하던 BRUSH객체는 h_old_brush에 저장
	HGDIOBJ h_old_brush = SelectObject(h_dc, h_brush);

	// 선을 표시하지 않는 속성으로 PEN 객체를 생성
	HPEN h_pen = CreatePen(PS_NULL, 0, WHITE);
	// DC에 생성한 PEN 객체를 저장하고
	// 기존에 사용하던 PEN객체는 h_old_pen에 저장
	HGDIOBJ h_old_pen = SelectObject(h_dc, h_pen);
	//----------------------------------------


	//----------------------------------------
	// 양 끝점(왼쪽위, 오른쪽 아래)을 기준으로 사각형을 그림
	Rectangle(h_dc, p1.x, p1.y, p1.x + p2.x, p1.y - p2.y);

	//----------------------------------------


	//----------------------------------------
	// 기존 PEN객체로 복귀한다
	SelectObject(h_dc, h_old_pen);
	// 자신이 만든 PEN객체를 삭제
	DeleteObject(h_pen);

	// 기존 BRUSH객체로 복귀한다
	SelectObject(h_dc, h_old_pen);
	// 자신이 만든 BRUSH객체를 삭제
	DeleteObject(h_pen);
	//----------------------------------------


	// DC값을 되돌려줌
	ReleaseDC(hWnd, h_dc);
}