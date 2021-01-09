#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[1024], str2[1024];

	/* 문자열을 입력받음 */
	printf("문자열 1: ");
	scanf("%s", str1);
	printf("문자열 2: ");
	scanf("%s", str2);

	/* strcat를 이용해 문자열을 복사해 뒤에 이어붙임 */
	strcat(strcat(str1," "), str2);

	printf("문자열1 + 문자열2: %s\n", str1);

	return 0;
}