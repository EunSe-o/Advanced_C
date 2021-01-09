#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

void Genrate(int square[][11], int size);
void Rotate(int square[][11], int size);
void Print(int square[][11], int size);

int main()
{
	int num, size = 0, square[11][11];
	char command[32];
	int i = 0;

	while (1)
	{
		printf("����(gen: ������ ����, rot: ������ ȸ��, exit: ����): ");
		scanf("%s", command);

		// strcmp�� �̿��� �Է¹��� ���ڸ� num������ ����� ���� 
		if (strcmp(command, "gen") == 0)
			num = 1;
		else if (strcmp(command, "rot") == 0)
			num = 2;
		else if (strcmp(command, "exit") == 0)
			num = 3;
		else
			num = 4;

		// switch���� �̿��� �Է¹��� ���ڿ� ���� ��� ���
		switch (num)
		{
		case 1: // gen�� �Է¹޾��� ��
			printf("\n������ ũ�� �Է�: ");
			scanf("%d", &size);

			// 3, 5, 7, 9, 11�� �ƴ� �ٸ� ���� ���� ����ó��
			if (size > 11 || size % 2 == 0 || size < 3)
			{
				printf("�߸��� �Է��Դϴ�.\n\n");
				size = i; // ���� �ùٸ��� �Է��ߴ� ������ ũ�⸦ �ҷ���
				break;
			}
			i = size; // �ùٸ��� �Է��� ������ ũ�� ����

			Genrate(square, size);
			break;

		case 2: // rot�� �Է¹޾��� ��
			// �������� ũ�⸦ ���� �Է¹��� �ʾ��� ���
			if (size == 0)
				printf("������ �������� �����ϴ�.\n");
			Rotate(square, size);
			break;

		case 3: // exit�� �Է¹޾��� ��
			printf("���α׷��� �����մϴ�.\n");
			return 0;

		default: // ���� �ٸ� ���ڸ� �Է¹޾��� ��
			printf("�߸��� �Է��Դϴ�.\n\n");
		}
	}

	return 0;
}

void Genrate(int square[][11], int size)
{
	int i = 0;
	int jtemp = size / 2;
	int itemp = 0;

	for (int i = 0; i < size; i++)
	{
		memset(square[i], 0, sizeof(square[i]));	//�迭�� 0���� �ʱ�ȭ ���ִ� �Լ�
	}

	for (i = 0; i < size * size; i++)
	{
		// �������� 1�� �Է��Ͽ� ó�� ������ ����
		if (i == 0)
		{
			square[i][jtemp] = 1;
			continue;
		}

		// �ش� ĭ�� ���ڰ� ä�����ִ� ��� �ش� ĭ �Ʒ��� ���ڸ� �Է�
		if (i % size == 0)
		{
			itemp++;

			// ���� ��� ���
			if (itemp < 0)
				itemp = size - 1;
			// ���� ��� ���
			if (jtemp >= size)
				jtemp = 0;
		}

		/* �������� ���ڰ� ä������ ���� ��� */
		else if (i % size != 0)
		{
			itemp--;
			jtemp++;

			// ���� ��� ���
			if (itemp < 0)
				itemp = size - 1;
			// ���� ��� ���
			if (jtemp >= size)
				jtemp = 0;
		}

		// �ش� ĭ�� ���� ����
		square[itemp][jtemp] = i + 1;
	}

	Print(square, size);
}


void Rotate(int square[][11], int size)
{
	int i, j, k = 0;
	int temp[11][11] = { 0 };

	// temp�迭�� ����� 90�� ȸ���� square�迭�� ���� ����
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			temp[j][size - i - 1] = square[i][j];
		}
	}

	// ����� ���� square�迭�� 90�� ȸ���� ���� �ٽ� ����
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			square[i][j] = temp[i][j];
		}
	}

	Print(square, size);
}

void Print(int square[][11], int size)
{
	int i, j = 0;

	// ĭ�� ���߾� ������ ���
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%3d\t", square[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}