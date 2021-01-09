#include <stdio.h>

int main(void)
{
	int arr[3][3][3];
	int i, j, k;

	/* 3중첩 반복문을 사용하여 각 배열에 해당하는 값 저장 */
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

	/* 3중첩 반복문을 사용하여 배열 출력 */
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