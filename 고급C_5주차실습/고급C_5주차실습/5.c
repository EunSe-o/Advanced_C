#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i, j = 0;
	char name[3][16] = { 0 };
	int score[3][3] = { 0 };

	for (i = 0; i < 3; i++)
	{
		printf("%d�� �̸�: ", i + 1);
		scanf("%s", name[i]);

		for (j = 0;; j++)
		{ //���� ������ �ùٸ��� �Է����� �� for�� ����
			printf("���� ����(0-100): ");
			scanf_s("%d", &score[i][0]);
			if (score[i][0] >= 0 && score[i][0] <= 100)
				break;
			printf("�߸��� �����Դϴ�.\n");
		}

		for (j = 0;; j++)
		{ //���� ������ �ùٸ��� �Է����� �� for�� ����
			printf("���� ����(0-100): ");
			scanf_s("%d", &score[i][1]);
			if (score[i][1] >= 0 && score[i][1] <= 100)
				break;
			printf("�߸��� �����Դϴ�.\n");
		}

		for (j = 0;; j++)
		{ //���� ������ �ùٸ��� �Է����� �� for�� ����
			printf("���� ����(0-100): ");
			scanf_s("%d", &score[i][2]);
			if (score[i][2] >= 0 && score[i][2] <= 100)
				break;
			printf("�߸��� �����Դϴ�.\n");
		}
		printf("\n");
	}

	printf("�̸�\t����\t����\t����\n");
	for (int i = 0; i < 3; i++)
	{ // �Է��� ������ ǥ�� ����� ���
		printf("%s\t%d\t%d\t%d\n", name[i], score[i][0], score[i][1], score[i][2]);
	}

	return 0;
}