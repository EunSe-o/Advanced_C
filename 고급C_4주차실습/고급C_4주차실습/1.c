#include <stdio.h>

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* pArr = arr;

	//�迭�� �ּ� (arr[0]�� �ּ�)�� �����
	printf("�迭�� �ּ�: %p\n", &arr);

	//�迭�� �� ������ �ּҸ� �����
	for (int i = 0; i < 5; i++)
		printf("�迭�� %d��° ������ �ּ�: %p\n", i, &arr[i]);
	printf("\n");

	//���� �����Ͱ� ����Ű�� �ּ�(arr�� �ּ�)�� �����
	printf("���� �����Ͱ� ����Ű�� �ּ�: %p\n", pArr);
	
	//0���� 1�� ������Ų �����Ͱ� ����Ű�� �ּҸ� �����
	for (int i = 0; i < 5; i++)
		printf("ũ�⸦ %d��ŭ ������Ų �����Ͱ� ����Ű�� �ּ�: %p\n", i, (pArr + i));
	printf("\n");

	return 0;
}