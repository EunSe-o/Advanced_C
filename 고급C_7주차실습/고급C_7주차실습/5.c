#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[1024]; //연산을 입력받을 문자열
	char op = NULL; //연산자를 저장할 변수
	int idx;        //연산자의 위치를 저장할 변수
	int length;

	printf("입력: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';     //fgets로 받아오는 개행문자 제거
	length = strlen(str);

	/* 입력 받은 문자열을 탐색하며 연산자를 찾고 그 위치를 저장한다. */
	for (int i = 0; i < length; i++)
	{
		if (str[i] < '0' || str[i] >'9')
		{
			if (op != NULL)
			{
				puts("잘못된 연산자입니다.");
				return -1;
			}
			op = str[i];
			str[i] = NULL;
			idx = i;
		}
	}

	/* switch문을 이용해 각 연산자를 입력받았을 경우의 결과를 출력한다. */
	switch (op)
	{
	case '\0': // 연산자가 없을 때 
		puts("연산자가 없습니다.");
		return -1;

	case '+':  // 연산자가 +일 때
		printf("결과: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) + atoi(str + idx + 1));
		break;

	case '-':  // 연산자가 -일 때
		printf("결과: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) - atoi(str + idx + 1));
		break;

	case '*':  // 연산자가 *일 때
		printf("결과: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) * atoi(str + idx + 1));
		break;

	case '/':  // 연산자가 /일 때
		printf("결과: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) / atoi(str + idx + 1));
		break; 

	default:   // 이외의 연산자를 입력받았을 때
		printf("잘못된 연산자입니다.\n");
		return -1;
	}

	return 0;
}