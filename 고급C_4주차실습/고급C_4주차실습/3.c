#include <stdio.h>

int main(void)
{
	/* ���� ���� */
	char str[] = "The limits of my language mean the limits of my world.";
	char* ptr = str;
	char let;
	int cnt = 0;

	/* ������ ���ڸ� ����ϰ� ã�� ���ڸ� �Է¹��� */
	printf("����: %s\n", ptr);
	printf("ã�� ����(a-z): ");
	scanf_s("%c", &let);

	/* �ݺ����� ������ �����͸� �̿��� �迭�� Ž���Ͽ�
	   �Է¹��� ���ڿ� ������ ���ڸ� ã�� ���� �� */
	for (int i = 0; i < (sizeof(str) / sizeof(char)); i++)
	{
		if (*(ptr + i) == let)
			cnt++;
	}

	printf("'%c'�� ����: %d��\n", let, cnt);

	return 0;
}