#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i, j = 0;
	int num[3][3];
	int temp;

	printf("9���� �� �Է�: ");
	for (i = 0; i < 3; i++)
	{ // 9���� ���� �Է¹޾� �迭�� ����
		for (j = 0; j < 3; j++)
			scanf("%d", &num[i][j]);
	}

	printf("�Էµ� ��\n");
	for (i = 0; i < 3; i++)
	{ // �Էµ� ���� 3x3���� ���
		for (j = 0; j < 3; j++)
			printf("%d\t", num[i][j]);
		printf("\n");
	}

	/* �Է¹��� �迭�� ���� ���� ������� ������ */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (num[i][j] < num[k][l])
					{
						temp = num[i][j];
						num[i][j] = num[k][l];
						num[k][l] = temp;
					}

					if (num[i][j] == num[k][l])
						break;
				}
			}
		}
	}

	printf("���ĵ� ��\n");
	for (i = 0; i < 3; i++)
	{ // ���ĵ� ���� 3x3���� ���
		for (j = 0; j < 3; j++)
			printf("%d\t", num[i][j]);
		printf("\n");
	}

	return 0;
}
