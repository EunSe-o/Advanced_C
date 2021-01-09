#pragma once
#pragma warning (disable:4996)
#include <stdio.h>

typedef struct  // ����ü �� ����
{
	int xpos;
	int ypos;
}Point;

typedef struct
{
	int x;
	int y;
}Coordinate;

int SetPoint(Point* p)  // x��ǥ�� y��ǥ�� �Է� ����
{
	printf("x��ǥ: ");
	scanf("%d", &p->xpos);

	printf("y��ǥ: ");
	scanf("%d", &p->ypos);
}

void PrintPoint(Point p) // x��ǥ�� y��ǥ ���
{
	printf("x��ǥ: %d, y��ǥ: %d\n", p.xpos, p.ypos);
}

void GetArea(Point pos1, Point pos2) // �簢���� ���̸� ���
{
	int area;
	Coordinate len;

	/* �簢���� ���� ���� ���ϱ� */
	if (pos2.xpos >= pos1.xpos)
		len.x = pos2.xpos - pos1.xpos;
	else
		len.x = pos1.xpos - pos2.xpos;

	/* �簢���� ���� ���� ���ϱ� */
	if (pos2.ypos >= pos1.ypos)
		len.y = pos2.ypos - pos1.ypos;
	else
		len.y = pos1.ypos - pos2.ypos;

	area = len.x * len.y;

	printf("�� ������ ���� �� �ִ� �簢���� ���̴� %d�Դϴ�.\n", area);
}

void GetPerimeter(Point pos1, Point pos2) // �簢���� �ѷ� ���
{
	int meter;
	Coordinate len;

	/* �簢���� ���� ���� ���ϱ� */
	if (pos2.xpos >= pos1.xpos)
		len.x = pos2.xpos - pos1.xpos;
	else
		len.x = pos1.xpos - pos2.xpos;

	/* �簢���� ���� ���� ���ϱ� */
	if (pos2.ypos >= pos1.ypos)
		len.y = pos2.ypos - pos1.ypos;
	else
		len.y = pos1.ypos - pos2.ypos;

	meter = (len.x) * 2 + (len.y) * 2;
	printf("�� ������ ���� �� �ִ� �簢���� �ѷ��� %d�Դϴ�.\n", meter);
}