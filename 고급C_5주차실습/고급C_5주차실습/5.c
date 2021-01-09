#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int i, j = 0;
	char name[3][16] = { 0 };
	int score[3][3] = { 0 };

	for (i = 0; i < 3; i++)
	{
		printf("%d번 이름: ", i + 1);
		scanf("%s", name[i]);

		for (j = 0;; j++)
		{ //국어 점수를 올바르게 입력했을 시 for문 종료
			printf("국어 점수(0-100): ");
			scanf_s("%d", &score[i][0]);
			if (score[i][0] >= 0 && score[i][0] <= 100)
				break;
			printf("잘못된 점수입니다.\n");
		}

		for (j = 0;; j++)
		{ //영어 점수를 올바르게 입력했을 시 for문 종료
			printf("영어 점수(0-100): ");
			scanf_s("%d", &score[i][1]);
			if (score[i][1] >= 0 && score[i][1] <= 100)
				break;
			printf("잘못된 점수입니다.\n");
		}

		for (j = 0;; j++)
		{ //수학 점수를 올바르게 입력했을 시 for문 종료
			printf("수학 점수(0-100): ");
			scanf_s("%d", &score[i][2]);
			if (score[i][2] >= 0 && score[i][2] <= 100)
				break;
			printf("잘못된 점수입니다.\n");
		}
		printf("\n");
	}

	printf("이름\t국어\t영어\t수학\n");
	for (int i = 0; i < 3; i++)
	{ // 입력한 정보를 표로 만들어 출력
		printf("%s\t%d\t%d\t%d\n", name[i], score[i][0], score[i][1], score[i][2]);
	}

	return 0;
}