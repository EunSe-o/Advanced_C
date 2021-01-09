#pragma warning (disable: 4996)
#include <stdio.h>

struct Time   // 생년월일을 입력받음
{
	int year;
	int month;
	int day;
};

struct person // 정보를 입력받음
{
	struct person* mate;
	char name[20];
	int age;
	struct Time birth;
};

int main(void)
{
	struct person p1, p2;  // 구조체 선언
	p1.mate = &p2;
	p2.mate = &p1;

	/* 정보를 입력받음 */
	printf("이름: ");
	scanf("%s", p1.name);
	printf("나이: ");
	scanf("%d", &p1.age);
	printf("생일: ");
	scanf("%d %d %d", &p1.birth.year, &p1.birth.month, &p1.birth.day);
	printf("친구의 이름: ");
	scanf("%s", p2.name);
	printf("친구의 나이: ");
	scanf("%d", &p2.age);
	printf("친구의 생일: ");
	scanf("%d %d %d", &p2.birth.year, &p2.birth.month, &p2.birth.day);

	/* 정보를 출력함 */
	printf("\n\n<정보>\n");
	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("생일: %d.%d.%d\n", p1.birth.year, p1.birth.month, p1.birth.day);
	printf("친구의 이름: %s\n", (p1.mate)->name);  // p2 대신 (p1.mate)->이용
	printf("친구의 나이: %d\n", (p1.mate)->age);
	printf("친구의 생일: %d.%d.%d\n", (p1.mate)->birth.year, (p1.mate)->birth.month, (p1.mate)->birth.day);

	return 0;
}