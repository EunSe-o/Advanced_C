#pragma once
#pragma warning (disable:4996)
#include <stdio.h>

typedef struct  // 구조체 형 정의
{
	int xpos;
	int ypos;
}Point;

typedef struct
{
	int x;
	int y;
}Coordinate;

int SetPoint(Point* p)  // x좌표와 y좌표를 입력 받음
{
	printf("x좌표: ");
	scanf("%d", &p->xpos);

	printf("y좌표: ");
	scanf("%d", &p->ypos);
}

void PrintPoint(Point p) // x좌표와 y좌표 출력
{
	printf("x좌표: %d, y좌표: %d\n", p.xpos, p.ypos);
}

void GetArea(Point pos1, Point pos2) // 사각형의 넓이를 출력
{
	int area;
	Coordinate len;

	/* 사각형의 가로 길이 구하기 */
	if (pos2.xpos >= pos1.xpos)
		len.x = pos2.xpos - pos1.xpos;
	else
		len.x = pos1.xpos - pos2.xpos;

	/* 사각형의 세로 길이 구하기 */
	if (pos2.ypos >= pos1.ypos)
		len.y = pos2.ypos - pos1.ypos;
	else
		len.y = pos1.ypos - pos2.ypos;

	area = len.x * len.y;

	printf("두 점으로 만들 수 있는 사각형의 넓이는 %d입니다.\n", area);
}

void GetPerimeter(Point pos1, Point pos2) // 사각형의 둘레 출력
{
	int meter;
	Coordinate len;

	/* 사각형의 가로 길이 구하기 */
	if (pos2.xpos >= pos1.xpos)
		len.x = pos2.xpos - pos1.xpos;
	else
		len.x = pos1.xpos - pos2.xpos;

	/* 사각형의 세로 길이 구하기 */
	if (pos2.ypos >= pos1.ypos)
		len.y = pos2.ypos - pos1.ypos;
	else
		len.y = pos1.ypos - pos2.ypos;

	meter = (len.x) * 2 + (len.y) * 2;
	printf("두 점으로 만들 수 있는 사각형의 둘레는 %d입니다.\n", meter);
}