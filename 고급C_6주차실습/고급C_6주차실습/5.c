#pragma warning (disable: 4996) 
#include <stdio.h>

int main(Void)
{
	int arr1[3][3], arr2[3][3];
	int(*ptr1)[3] = arr1, (*ptr2)[3] = arr2; //�迭 ������ ����
	int sum;
	int i, j;

	/* ���1 �Է¹��� */
	printf("���1 �Է�\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &ptr1[i][j]);
		}
	}	
	
	/* ���2�� �Է¹��� */
	printf("\n���2 �Է�\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &ptr2[i][j]);
		}
	}

	/* ��� ���� �̿��� ���1 x ���2�� ����� */
	printf("���1 x ���2\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%3d", (ptr1[i][0] * ptr2[0][j])+ (ptr1[i][1] * ptr2[1][j])+(ptr1[i][2] * ptr2[2][j]));
		}
		printf("\n");
	}

	return 0;
}