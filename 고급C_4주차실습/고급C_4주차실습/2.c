#include <stdio.h>

int main(void)
{
	int arr[10];
	int* pArr = arr;

	//�����͸� �̿��� �� �迭�� ���� ����
	for (int i = 0; i < 10; i++)
		*(pArr + i) = i;
	
	//�迭�� ����� ���� �����͸� �̿��� ���
	for (pArr = arr; pArr != arr + (sizeof(arr) / sizeof(int)); pArr++)
		printf("%2d", *pArr);
	printf("\n");

	return 0;
}