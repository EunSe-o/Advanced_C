#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[1024], str2[1024];

	/* ���ڿ��� �Է¹��� */
	printf("���ڿ� 1: ");
	scanf("%s", str1);
	printf("���ڿ� 2: ");
	scanf("%s", str2);

	/* strcat�� �̿��� ���ڿ��� ������ �ڿ� �̾���� */
	strcat(strcat(str1," "), str2);

	printf("���ڿ�1 + ���ڿ�2: %s\n", str1);

	return 0;
}