#include <stdio.h>

void get_array(int* arr);
void Odd_Or_Even(int* arr, int num);

int main(void)
{
	int arr[10];

	get_array(arr);

	printf("\n홀수 출력: ");
	Odd_Or_Even(arr, 1);

	printf("\n짝수 출력: ");
	Odd_Or_Even(arr, 0);

	return 0;
}

void get_array(int* arr)
{
	printf("10개의 수 입력\n");
	/* 10 개의 수를 입력받아 배열에 저장 */
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &arr[i]);
}

void Odd_Or_Even(int* arr, int num)
{
	for (int i = 0; i < 10; i++)
	{
		/* 2로 나누어 홀수인지 짝수인지 구분함 */
		if (arr[i] % 2 == num)
			printf("%d ", arr[i]);
	}
}