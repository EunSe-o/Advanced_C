#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i = 0;
	int* size = (int*)malloc(sizeof(int));        // malloc 함수를 호출해
	int* parr = (int*)malloc(sizeof(int) * 20);  // 메모리 동적 할당 이용

	printf("크기: ");
	scanf("%d", &size);  // 크기를 입력받음

	printf("입력: ");
	for (i = 0; i < size; i++)
		scanf("%d", &parr[i]);  // 배열을 입력받음

	printf("arr:");
	for (i = 0; i < size; i++)
		printf(" %d", parr[i]); // 입력받은 순서대로 출력

	free(size); // free함수를 이용해 힙 영역에 할당된 메모리 공간 해제
	free(parr);

	return 0;
}