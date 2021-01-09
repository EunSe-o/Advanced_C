#pragma warning (disable:4996)
#include <stdio.h>

typedef struct  // 구조체 선언
{
	char name[32];
	int price;
}goods;

void swap(goods* num1, goods* num2) // swap 함수
{
	goods temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(goods *arr, int size) // bubble_sort 함수
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if ((arr[j].price) < (arr[j+1].price))
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main(void)
{
	int num, sum = 0;
	goods* part, temp;
	int i, j = 0;

	printf("갯수 입력: ");
	scanf("%d", &num);

	/* 메모리 할당 */
	part = malloc(sizeof(goods) * num);

	/* 정보를 입력 받음 */
	for (i = 0; i < num; i++)
	{
		printf("상품 이름: ");
		scanf("%s", part[i].name);
		printf("가격: ");
		scanf("%d", &part[i].price);
	}

	bubble_sort(part, num); // bubble_sort 함수를 이용해 정렬

	/* 가격 순서대로 정렬하여 출력함 */
	printf("\n정렬 결과\n");
	for (i = 0; i < num; i++)
	{
		printf("상품 이름: %s, 가격: %d\n", part[i].name, part[i].price);
		sum += part[i].price;
	}
	printf("가격 총합: %d\n", sum); // 가격 총합 출력

	return 0;
}