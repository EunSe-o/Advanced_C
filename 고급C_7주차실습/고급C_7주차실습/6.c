#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[5][2][32] =
	{
		{"apple", "���"},
	{"banana", "�ٳ���"},
	{"orange", "������"},
	{"lemon", "����"},
	{"grape","����"}
	};

	char str[32];
	int i, j = 0;

	for (i = 0; ; i++)
	{
		printf("�Է�(����: exit): ");
		scanf("%s", str);

		/* exit�� �Է¹����� ���α׷��� ������ */
		if (!strcmp(str, "exit"))
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		/* �迭�� �ִ� �ѱ� �ܾ �Է��ϸ� ���ܾ ����� */
		for (j = 0; j < 5; j++)
		{
			if (!strcmp(arr[j][1], str))
			{
				printf("%s: %s\n", arr[j][1], arr[j][0]);
				break;
			}
			if (j == 4)
				printf("���� �ܾ��Դϴ�.\n");
		}
	}

	return 0;
}