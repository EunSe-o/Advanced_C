#include <stdio.h>

int main(void)
{
	/* ������ ������ �迭 ���� */
	int num1 = 56, num2 = 53, num3 = 45, num4 = 77;
	int* pNum[4] = { &num1, &num2, &num3, &num4 };

	//������ �迭�� �Է¹��� �� �������� �ּڰ��� �����
	printf("num1�� �ּ�: %p\n", &num1);
	printf("num2�� �ּ�: %p\n", &num2);
	printf("num3�� �ּ�: %p\n", &num3);
	printf("num4�� �ּ�: %p\n\n", &num4);

	//������ �迭�� n��° ���Ұ� ����Ű�� �ּ�(������ �ּ�)�� �����
	for (int i = 0; i < 4; i++)
		printf("������ �迭�� %d��° ���Ұ� ����Ű�� �ּ�: %p\n", i + 1, pNum[i]);

	printf("\n������ �迭�� �ּ�: %p\n", &pNum);

	//������ �迭�� ������ �ּҸ� �����
	for (int i = 0; i < 4; i++)
		printf("������ �迭�� %d��° ������ �ּ�: %p\n", i + 1, &pNum[i]);

	return 0;
}