#pragma warning(disable:4996)
#include <stdio.h>

typedef struct
{
	char name[32];
	char grade[32];
}classes;

typedef struct
{
	char name[32];
	char id[32];
	classes* attend;
}student;

int main(void) 
{
	int num, i;
	student person;

	/* ������ �Է� ���� */
	printf("�̸�: ");
	scanf("%s", person.name);
	printf("�й�: ");
	scanf("%s", person.id);
	printf("���� ���� ��: ");
	scanf("%d", &num);

	person.attend = malloc(sizeof(student)); // ���� �޸𸮸� �Ҵ�
	for (i = 0; i < num; i++)
	{ // ������ ������ �Է� ����
		printf("���� �̸�: ");
		scanf("%s", person.attend[i].name);
		printf("���� ����: ");
		scanf("%s", person.attend[i].grade);
	}

	/* ���� ��� */
	printf("\n\n%s�� ����\n", person.name);
	printf("�̸�: %s, �й�: %s\n", person.name, person.id);
	for (i = 0; i < num; i++)
		printf("����: %s, ����: %s\n", person.attend[i].name, person.attend[i].grade);
	printf("\n");

	free(person.attend);  // �Ҵ� �޾Ҵ� �޸� ����
	return 0;
}