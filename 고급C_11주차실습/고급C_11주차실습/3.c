#pragma warning (disable: 4996)
#include <stdio.h>

struct Time   // ��������� �Է¹���
{
	int year;
	int month;
	int day;
};

struct person // ������ �Է¹���
{
	struct person* mate;
	char name[20];
	int age;
	struct Time birth;
};

int main(void)
{
	struct person p1, p2;  // ����ü ����
	p1.mate = &p2;
	p2.mate = &p1;

	/* ������ �Է¹��� */
	printf("�̸�: ");
	scanf("%s", p1.name);
	printf("����: ");
	scanf("%d", &p1.age);
	printf("����: ");
	scanf("%d %d %d", &p1.birth.year, &p1.birth.month, &p1.birth.day);
	printf("ģ���� �̸�: ");
	scanf("%s", p2.name);
	printf("ģ���� ����: ");
	scanf("%d", &p2.age);
	printf("ģ���� ����: ");
	scanf("%d %d %d", &p2.birth.year, &p2.birth.month, &p2.birth.day);

	/* ������ ����� */
	printf("\n\n<����>\n");
	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("����: %d.%d.%d\n", p1.birth.year, p1.birth.month, p1.birth.day);
	printf("ģ���� �̸�: %s\n", (p1.mate)->name);  // p2 ��� (p1.mate)->�̿�
	printf("ģ���� ����: %d\n", (p1.mate)->age);
	printf("ģ���� ����: %d.%d.%d\n", (p1.mate)->birth.year, (p1.mate)->birth.month, (p1.mate)->birth.day);

	return 0;
}