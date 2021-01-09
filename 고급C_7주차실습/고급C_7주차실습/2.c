#include <stdio.h>

void EmptyFunction()
{
	printf("Nothing\n");
}

int main(void)
{
	int num = 33;
	char string[] = "Hello World!";
	void* ptr; // void포인터 선언

	ptr = &num;
	printf("num의 주소: %p\n", ptr);

	ptr = string;
	printf("문자열의 주소: %p\n", ptr);

	ptr = EmptyFunction; // void 포인터를 이용해 함수의 주솟값을 입력받음
	printf("함수의 주소: %p\n", ptr);

	return 0;
}