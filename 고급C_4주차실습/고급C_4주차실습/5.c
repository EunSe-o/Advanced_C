#include <stdio.h>

int main(void)
{
	/* 변수와 포인터 배열 선언 */
	int num1 = 56, num2 = 53, num3 = 45, num4 = 77;
	int* pNum[4] = { &num1, &num2, &num3, &num4 };

	//포인터 배열로 입력받은 각 변수들의 주솟값을 출력함
	printf("num1의 주소: %p\n", &num1);
	printf("num2의 주소: %p\n", &num2);
	printf("num3의 주소: %p\n", &num3);
	printf("num4의 주소: %p\n\n", &num4);

	//포인터 배열의 n번째 원소가 가리키는 주소(변수의 주소)를 출력함
	for (int i = 0; i < 4; i++)
		printf("포인터 배열의 %d번째 원소가 가리키는 주소: %p\n", i + 1, pNum[i]);

	printf("\n포인터 배열의 주소: %p\n", &pNum);

	//포인터 배열의 원소의 주소를 출력함
	for (int i = 0; i < 4; i++)
		printf("포인터 배열의 %d번째 원소의 주소: %p\n", i + 1, &pNum[i]);

	return 0;
}