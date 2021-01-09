#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int num = 0;
	int count = 0;
	int* ptr = NULL;
	int i = 0;

	while (1)
	{
		printf("양의 정수를 입력하세요(종료: -1): ");
		scanf("%d", &num);

		if (num == -1)
			break;

		//realloc을 사용하여 메모리 할당
		ptr = (int*)realloc(ptr, sizeof(int)*(count+1)); 
		ptr[count] = num; 
		count++;
	}

	/* 순서대로 출력 */
	for (i = 0; i < count; i++)
		printf("ptr[%d]: %d\n", i, ptr[i]);

	free(ptr);

	return 0;
}