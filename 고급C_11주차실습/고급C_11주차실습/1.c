#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i = 0;
	int* size = (int*)malloc(sizeof(int));        // malloc �Լ��� ȣ����
	int* parr = (int*)malloc(sizeof(int) * 20);  // �޸� ���� �Ҵ� �̿�

	printf("ũ��: ");
	scanf("%d", &size);  // ũ�⸦ �Է¹���

	printf("�Է�: ");
	for (i = 0; i < size; i++)
		scanf("%d", &parr[i]);  // �迭�� �Է¹���

	printf("arr:");
	for (i = 0; i < size; i++)
		printf(" %d", parr[i]); // �Է¹��� ������� ���

	free(size); // free�Լ��� �̿��� �� ������ �Ҵ�� �޸� ���� ����
	free(parr);

	return 0;
}