#include <stdio.h>

int main(void)
{
	/* 변수, 포인터 배열 선언 */
	int sum = 0;
	int num1 = 56, num2 = 53, num3 = 45, num4 = 77;
	int* pNum[4] = { &num1, &num2, &num3, &num4 };

	//각 배열의 값들을 모두 합함
	for (int i = 0; i < 4; i++)
		sum += *pNum[i];

		printf("합: %d\n", sum);
	return 0;
}