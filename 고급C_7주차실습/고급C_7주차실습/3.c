#include <stdio.h>

int main(int argc, char ** argv)
{
	printf("전달받은 인자 수: %d\n", argc-1);

	for (int i = 1; argv[i]!= NULL ; i++) // 문장이 끝나면 종료
		printf("%d번째 인자: %s\n", i, argv[i]); //인자 출력

	return 0;
}