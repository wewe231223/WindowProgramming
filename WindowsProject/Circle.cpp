#include "Circle.h"

Circle::Circle() : center { Point{ 0, 0 } }, rad{ 0 } {}

Circle::Circle(HWND hWnd, Point center, int rad) : hWnd{hWnd}, center { center }, rad{ rad } {}

Circle::~Circle() {}

void Circle::draw() {
	// ���� �������� DC���� �޾ƿ�
	HDC h_dc = GetDC(hWnd);


	//----------------------------------------
	// �ʷϻ����� ä������ BRUSH ��ü ����
	HBRUSH h_brush = CreateSolidBrush(GREEN);
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
	// �߽���ǥ�� �������� ��������ŭ ���� �׸�
	Ellipse(h_dc, center.x - rad, center.y + rad,
		center.x + rad, center.y - rad);
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