#include <stdio.h>

int main(int argc, char ** argv)
{
	printf("���޹��� ���� ��: %d\n", argc-1);

	for (int i = 1; argv[i]!= NULL ; i++) // ������ ������ ����
		printf("%d��° ����: %s\n", i, argv[i]); //���� ���

	return 0;
}