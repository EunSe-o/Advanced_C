#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h> //������� ����

void reverse(char* str)
{
	int i = 0;
	char temp = 0;

	/* ���� �ڿ� �ִ� ���ں��� ������� ��µǵ��� �迭�� �ٲ� */
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

	printf("�Է�: ");
	scanf("%s", str);

	reverse(str); //reverse �Լ� ȣ��
	printf("��� : %s\n", str);

	return 0;
}