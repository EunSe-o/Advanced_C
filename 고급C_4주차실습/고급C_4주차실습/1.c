#include <stdio.h>

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* pArr = arr;

	//배열의 주소 (arr[0]의 주소)를 출력함
	printf("배열의 주소: %p\n", &arr);

	//배열의 각 원소의 주소를 출력함
	for (int i = 0; i < 5; i++)
		printf("배열의 %d번째 원소의 주소: %p\n", i, &arr[i]);
	printf("\n");

	//최초 포인터가 가리키는 주소(arr의 주소)를 출력함
	printf("최초 포인터가 가리키는 주소: %p\n", pArr);
	
	//0부터 1씩 증가시킨 포인터가 가리키는 주소를 출력함
	for (int i = 0; i < 5; i++)
		printf("크기를 %d만큼 증가시킨 포인터가 가리키는 주소: %p\n", i, (pArr + i));
	printf("\n");

	return 0;
}