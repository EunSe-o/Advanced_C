#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	char str1[1024], str2[1024], str3[1024], str4[1024];
	char* ptr[4] = { str1, str2, str3, str4 };

	//반복문을 이용해 문자열을 입력받아 배열에 저장
	for (int i = 0; i < 4; i++)
	{
		printf("입력: ");
		scanf("%s", ptr[i]);
	}

	//반복문을 이용해 입력받았던 문자열을 출력함
	for (int i = 0; i < 4; i++)
		printf("%d번째 문자열: %s\n", i + 1, ptr[i]);

	return 0;
}