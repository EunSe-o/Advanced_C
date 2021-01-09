#include <stdio.h>

int main(void)
{
	int arr[10];
	int* pArr = arr;

	//포인터를 이용해 각 배열에 값을 저장
	for (int i = 0; i < 10; i++)
		*(pArr + i) = i;
	
	//배열에 저장된 값을 포인터를 이용해 출력
	for (pArr = arr; pArr != arr + (sizeof(arr) / sizeof(int)); pArr++)
		printf("%2d", *pArr);
	printf("\n");

	return 0;
}