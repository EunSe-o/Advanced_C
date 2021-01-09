#include <stdio.h>

int main(void)
{
	/* 변수 선언 */
	char str[] = "The limits of my language mean the limits of my world.";
	char* ptr = str;
	char let;
	int cnt = 0;

	/* 저장한 문자를 출력하고 찾는 글자를 입력받음 */
	printf("문장: %s\n", ptr);
	printf("찾는 글자(a-z): ");
	scanf_s("%c", &let);

	/* 반복문을 돌리며 포인터를 이용해 배열을 탐색하여
	   입력받은 문자와 동일한 문자를 찾고 수를 셈 */
	for (int i = 0; i < (sizeof(str) / sizeof(char)); i++)
	{
		if (*(ptr + i) == let)
			cnt++;
	}

	printf("'%c'의 갯수: %d개\n", let, cnt);

	return 0;
}