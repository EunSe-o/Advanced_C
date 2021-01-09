#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int arr[3][3];
	int(*Aptr)[3] = arr; //배열 arr을 가리키는 포인터
	int* ptr; //최댓값을 가리키는 포인터
	int i, j = 0;

	/* 숫자를 입력받음 */
	printf("숫자 9개 입력\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &Aptr[i][j]);
		}
	}

	/* 반복문을 이용해 배열을 탐색하며 최댓값을 찾음 */
	ptr = Aptr[0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (Aptr[i][j] > * ptr)
				ptr = &Aptr[i][j];
		}
	}

	/* 최댓값의 위치를 출력 */
	printf("최댓값의 위치: [%d, %d]\n", (ptr - Aptr[0]) / 3, (ptr - Aptr[0]) % 3);

	return 0;
}