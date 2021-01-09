#include <stdio.h>

void get_array(int* arr, int num);
void print_array(int* arr, int num);

int main(void)
{
	int arr[5];

	/* 함수 호출 */
	get_array(arr, 5);
	print_array(arr, 5);

	return 0;
}

void get_array(int* arr, int num)
{
	/* 5개의 수를 입력받아 배열에 저장 */
	printf("%d개의 수 입력\n", num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", (arr + i));
}

void print_array(int* arr, int num)
{
	/* 입력받아 배열에 저장한 수들을 출력함 */
	printf("\n입력 결과\n");
	for (int i = 0; i < num; i++)
		printf("%d\n", *(arr + i));
}