#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	char str1[1024], str2[1024], str3[1024], str4[1024];
	char* ptr[4] = { str1, str2, str3, str4 };

	//�ݺ����� �̿��� ���ڿ��� �Է¹޾� �迭�� ����
	for (int i = 0; i < 4; i++)
	{
		printf("�Է�: ");
		scanf("%s", ptr[i]);
	}

	//�ݺ����� �̿��� �Է¹޾Ҵ� ���ڿ��� �����
	for (int i = 0; i < 4; i++)
		printf("%d��° ���ڿ�: %s\n", i + 1, ptr[i]);

	return 0;
}