#include "Rectangle.h"

Rect::Rect() {}

Rect::Rect(HWND hWnd, Point p1, Point p2) : hWnd{ hWnd }, p1{ p1 }, p2{ p2 } {}

Rect::~Rect() {}

void Rect::draw() {
	// ���� �������� DC���� �޾ƿ�
	HDC h_dc = GetDC(hWnd);


	//----------------------------------------
	// �Ķ������� ä������ BRUSH ��ü ����
	HBRUSH h_brush = CreateSolidBrush(BLUE);
	// DC�� ������ BRUSH ��ü�� �����ϰ�
	// ������ ����ϴ� BRUSH��ü�� h_old_brush�� ����
	HGDIOBJ h_old_brush = SelectObject(h_dc, h_brush);

	// ���� ǥ������ �ʴ� �Ӽ����� PEN ��ü�� ����
	HPEN h_pen = CreatePen(PS_NULL, 0, WHITE);
	// DC�� ������ PEN ��ü�� �����ϰ�
	// ������ ����ϴ� PEN��ü�� h_old_pen�� ����
	HGDIOBJ h_old_pen = SelectObject(h_dc, h_pen);
	//----------------------------------------


	//----------------------------------------
	// �� ����(������, ������ �Ʒ�)�� �������� �簢���� �׸�
	Rectangle(h_dc, p1.x, p1.y, p1.x + p2.x, p1.y - p2.y);

	//----------------------------------------


	//----------------------------------------
	// ���� PEN��ü�� �����Ѵ�
	SelectObject(h_dc, h_old_pen);
	// �ڽ��� ���� PEN��ü�� ����
	DeleteObject(h_pen);

	// ���� BRUSH��ü�� �����Ѵ�
	SelectObject(h_dc, h_old_pen);
	// �ڽ��� ���� BRUSH��ü�� ����
	DeleteObject(h_pen);
	//----------------------------------------


	// DC���� �ǵ�����
	ReleaseDC(hWnd, h_dc);
}