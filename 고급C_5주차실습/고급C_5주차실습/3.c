#include <stdio.h>

void get_array(int* arr, int num);
void print_array(int* arr, int num);

int main(void)
{
	int arr[5];

	/* �Լ� ȣ�� */
	get_array(arr, 5);
	print_array(arr, 5);

	return 0;
}

void get_array(int* arr, int num)
{
	/* 5���� ���� �Է¹޾� �迭�� ���� */
	printf("%d���� �� �Է�\n", num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", (arr + i));
}

void print_array(int* arr, int num)
{
	/* �Է¹޾� �迭�� ������ ������ ����� */
	printf("\n�Է� ���\n");
	for (int i = 0; i < num; i++)
		printf("%d\n", *(arr + i));
}