#include <stdio.h>

int main(void)
{
	/* ����, ������ �迭 ���� */
	int sum = 0;
	int num1 = 56, num2 = 53, num3 = 45, num4 = 77;
	int* pNum[4] = { &num1, &num2, &num3, &num4 };

	//�� �迭�� ������ ��� ����
	for (int i = 0; i < 4; i++)
		sum += *pNum[i];

		printf("��: %d\n", sum);
	return 0;
}