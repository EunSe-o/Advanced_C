#pragma warning (disable: 4996) 
#include <stdio.h>

struct Time  // ��������� �Է¹޴� ����ü
{
	int year;
	int month;
	int day;
};

struct person  // ������ �Է¹޴� ����ü
{
	char name[20];
	int age;
	struct Time birth;
};

int main(void)
{
	struct person p1; // ����ü ����

	/* ������ �Է� ���� */
	printf("�̸�: ");
	scanf("%s", p1.name);
	printf("����: ");
	scanf("%d", &p1.age);
	printf("�������: ");
	scanf("%d %d %d", &p1.birth.year, &p1.birth.month, &p1.birth.day);

	/* ������ ����� */
	printf("\n\n<����>\n");
	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�������: %d.%d.%d\n", p1.birth.year, p1.birth.month, p1.birth.day);

	return 0;
}