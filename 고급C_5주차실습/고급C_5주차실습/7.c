#include <stdio.h>

int main(void)
{
	int arr[3][3][3];
	int i, j, k;

	/* 3��ø �ݺ����� ����Ͽ� �� �迭�� �ش��ϴ� �� ���� */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				arr[i][j][k] = (i + 1) * 100 + (j + 1) * 10 + (k + 1);
			}
		}
	}

	/* 3��ø �ݺ����� ����Ͽ� �迭 ��� */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				printf("%5d", arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}