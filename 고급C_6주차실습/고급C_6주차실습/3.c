#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int arr[3][3];
	int(*Aptr)[3] = arr; //�迭 arr�� ����Ű�� ������
	int* ptr; //�ִ��� ����Ű�� ������
	int i, j = 0;

	/* ���ڸ� �Է¹��� */
	printf("���� 9�� �Է�\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &Aptr[i][j]);
		}
	}

	/* �ݺ����� �̿��� �迭�� Ž���ϸ� �ִ��� ã�� */
	ptr = Aptr[0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (Aptr[i][j] > * ptr)
				ptr = &Aptr[i][j];
		}
	}

	/* �ִ��� ��ġ�� ��� */
	printf("�ִ��� ��ġ: [%d, %d]\n", (ptr - Aptr[0]) / 3, (ptr - Aptr[0]) % 3);

	return 0;
}