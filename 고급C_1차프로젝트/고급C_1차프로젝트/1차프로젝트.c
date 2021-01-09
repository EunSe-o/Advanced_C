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
		printf("동작(gen: 마방진 생성, rot: 마방진 회전, exit: 종료): ");
		scanf("%s", command);

		// strcmp를 이용해 입력받은 문자를 num변수에 상수로 저장 
		if (strcmp(command, "gen") == 0)
			num = 1;
		else if (strcmp(command, "rot") == 0)
			num = 2;
		else if (strcmp(command, "exit") == 0)
			num = 3;
		else
			num = 4;

		// switch문을 이용해 입력받은 문자에 따른 결과 출력
		switch (num)
		{
		case 1: // gen을 입력받았을 때
			printf("\n마방진 크기 입력: ");
			scanf("%d", &size);

			// 3, 5, 7, 9, 11이 아닌 다른 수에 대한 예외처리
			if (size > 11 || size % 2 == 0 || size < 3)
			{
				printf("잘못된 입력입니다.\n\n");
				size = i; // 전에 올바르게 입력했던 마방진 크기를 불러옴
				break;
			}
			i = size; // 올바르게 입력한 마방진 크기 저장

			Genrate(square, size);
			break;

		case 2: // rot을 입력받았을 때
			// 마방진의 크기를 먼저 입력받지 않았을 경우
			if (size == 0)
				printf("생성된 마방진이 없습니다.\n");
			Rotate(square, size);
			break;

		case 3: // exit을 입력받았을 때
			printf("프로그램을 종료합니다.\n");
			return 0;

		default: // 외의 다른 문자를 입력받았을 때
			printf("잘못된 입력입니다.\n\n");
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
		memset(square[i], 0, sizeof(square[i]));	//배열을 0으로 초기화 해주는 함수
	}

	for (i = 0; i < size * size; i++)
	{
		// 마방진에 1을 입력하여 처음 차리를 잡음
		if (i == 0)
		{
			square[i][jtemp] = 1;
			continue;
		}

		// 해당 칸에 숫자가 채워져있는 경우 해당 칸 아래에 숫자를 입력
		if (i % size == 0)
		{
			itemp++;

			// 행을 벗어난 경우
			if (itemp < 0)
				itemp = size - 1;
			// 열을 벗어난 경우
			if (jtemp >= size)
				jtemp = 0;
		}

		/* 마방진에 숫자가 채워지지 않은 경우 */
		else if (i % size != 0)
		{
			itemp--;
			jtemp++;

			// 행을 벗어난 경우
			if (itemp < 0)
				itemp = size - 1;
			// 열을 벗어난 경우
			if (jtemp >= size)
				jtemp = 0;
		}

		// 해당 칸에 값을 저장
		square[itemp][jtemp] = i + 1;
	}

	Print(square, size);
}


void Rotate(int square[][11], int size)
{
	int i, j, k = 0;
	int temp[11][11] = { 0 };

	// temp배열을 만들어 90도 회전한 square배열의 값을 저장
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			temp[j][size - i - 1] = square[i][j];
		}
	}

	// 출력을 위해 square배열에 90도 회전한 값을 다시 저장
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

	// 칸에 맞추어 마방진 출력
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