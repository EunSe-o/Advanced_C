#pragma warning (disable:4996)
#include <stdio.h>

typedef struct  // ����ü ����
{
	char name[32];
	int price;
}goods;

void swap(goods* num1, goods* num2) // swap �Լ�
{
	goods temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(goods *arr, int size) // bubble_sort �Լ�
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

	printf("���� �Է�: ");
	scanf("%d", &num);

	/* �޸� �Ҵ� */
	part = malloc(sizeof(goods) * num);

	/* ������ �Է� ���� */
	for (i = 0; i < num; i++)
	{
		printf("��ǰ �̸�: ");
		scanf("%s", part[i].name);
		printf("����: ");
		scanf("%d", &part[i].price);
	}

	bubble_sort(part, num); // bubble_sort �Լ��� �̿��� ����

	/* ���� ������� �����Ͽ� ����� */
	printf("\n���� ���\n");
	for (i = 0; i < num; i++)
	{
		printf("��ǰ �̸�: %s, ����: %d\n", part[i].name, part[i].price);
		sum += part[i].price;
	}
	printf("���� ����: %d\n", sum); // ���� ���� ���

	return 0;
}