#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[5][2][32] =
	{
		{"apple", "사과"},
	{"banana", "바나나"},
	{"orange", "오렌지"},
	{"lemon", "레몬"},
	{"grape","포도"}
	};

	char str[32];
	int i, j = 0;

	for (i = 0; ; i++)
	{
		printf("입력(종료: exit): ");
		scanf("%s", str);

		/* exit를 입력받으면 프로그램을 종료함 */
		if (!strcmp(str, "exit"))
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		/* 배열에 있는 한글 단어를 입력하면 영단어를 출력함 */
		for (j = 0; j < 5; j++)
		{
			if (!strcmp(arr[j][1], str))
			{
				printf("%s: %s\n", arr[j][1], arr[j][0]);
				break;
			}
			if (j == 4)
				printf("없는 단어입니다.\n");
		}
	}

	return 0;
}