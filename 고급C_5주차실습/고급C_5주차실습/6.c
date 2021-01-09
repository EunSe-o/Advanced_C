#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i, j = 0;
	int num[3][3];
	int temp;

	printf("9개의 수 입력: ");
	for (i = 0; i < 3; i++)
	{ // 9개의 수를 입력받아 배열에 저장
		for (j = 0; j < 3; j++)
			scanf("%d", &num[i][j]);
	}

	printf("입력된 수\n");
	for (i = 0; i < 3; i++)
	{ // 입력된 수를 3x3으로 출력
		for (j = 0; j < 3; j++)
			printf("%d\t", num[i][j]);
		printf("\n");
	}

	/* 입력받은 배열을 작은 숫자 순서대로 정렬함 */
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

	printf("정렬된 수\n");
	for (i = 0; i < 3; i++)
	{ // 정렬된 수를 3x3으로 출력
		for (j = 0; j < 3; j++)
			printf("%d\t", num[i][j]);
		printf("\n");
	}

	return 0;
}
