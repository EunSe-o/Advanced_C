#include "11-6.h"

int main(void)
{
	Point p1, p2;

	SetPoint(&p1);
	SetPoint(&p2);
	PrintPoint(p1);
	PrintPoint(p2);
	GetArea(p1, p2);
	GetPerimeter(p1, p2);

	return 0;
}

