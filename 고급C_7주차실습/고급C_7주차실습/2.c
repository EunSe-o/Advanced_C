#include <stdio.h>

void EmptyFunction()
{
	printf("Nothing\n");
}

int main(void)
{
	int num = 33;
	char string[] = "Hello World!";
	void* ptr; // void������ ����

	ptr = &num;
	printf("num�� �ּ�: %p\n", ptr);

	ptr = string;
	printf("���ڿ��� �ּ�: %p\n", ptr);

	ptr = EmptyFunction; // void �����͸� �̿��� �Լ��� �ּڰ��� �Է¹���
	printf("�Լ��� �ּ�: %p\n", ptr);

	return 0;
}