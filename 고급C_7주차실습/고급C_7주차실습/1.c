#include <stdio.h>

int sum(int a, int b)
{
	return a + b;
}

int main(void)
{
	int num1 = 20, num2 = 30;

	int (*fptr) (int, int) = sum; // 함수 포인터 선언

	/* 함수 포인터를 이용해 출력 */
	printf("%d + %d = %d\n", num1, num2, fptr(num1, num2));

	return 0;
}