#include <stdio.h>

void get_array(int* arr);
void Odd_Or_Even(int* arr, int num);

int main(void)
{
	int arr[10];

	get_array(arr);

	printf("\nȦ�� ���: ");
	Odd_Or_Even(arr, 1);

	printf("\n¦�� ���: ");
	Odd_Or_Even(arr, 0);

	return 0;
}

void get_array(int* arr)
{
	printf("10���� �� �Է�\n");
	/* 10 ���� ���� �Է¹޾� �迭�� ���� */
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &arr[i]);
}

void Odd_Or_Even(int* arr, int num)
{
	for (int i = 0; i < 10; i++)
	{
		/* 2�� ������ Ȧ������ ¦������ ������ */
		if (arr[i] % 2 == num)
			printf("%d ", arr[i]);
	}
}