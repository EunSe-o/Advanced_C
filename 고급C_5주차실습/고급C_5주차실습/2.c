#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h> //헤더파일 선언

void reverse(char* str)
{
	int i = 0;
	char temp = 0;

	/* 가장 뒤에 있는 문자부터 순서대로 출력되도록 배열을 바꿈 */
	for (i = 0; i < strlen(str) / 2; i++)
	{
		temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = temp;
	}
}

int main(void)
{
	char str[1024];

	printf("입력: ");
	scanf("%s", str);

	reverse(str); //reverse 함수 호출
	printf("결과 : %s\n", str);

	return 0;
}