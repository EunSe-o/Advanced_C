#include <stdio.h>

int main(void)
{
	// �迭 �� �迭 ������, ���� ����
	int arr1[3][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	int arr2[5][3];
	int(*ptr1)[5] = arr1;
	int(*ptr2)[3] = arr2;
	int i, j = 0;

	// ptr2�� ptr1�� �迭�� ��� ���� �ٲپ� ����
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			ptr2[j][i] = ptr1[i][j];
		}
	}

	// ptr2 ���
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%3d", ptr2[i][j]);
		}
		printf("\n");
	}

	return 0;
}