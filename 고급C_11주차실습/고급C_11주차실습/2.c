#pragma warning (disable: 4996) 
#include <stdio.h>

struct Time  // 생년월일을 입력받는 구조체
{
	int year;
	int month;
	int day;
};

struct person  // 정보를 입력받는 구조체
{
	char name[20];
	int age;
	struct Time birth;
};

int main(void)
{
	struct person p1; // 구조체 선언

	/* 정보를 입력 받음 */
	printf("이름: ");
	scanf("%s", p1.name);
	printf("나이: ");
	scanf("%d", &p1.age);
	printf("생년월일: ");
	scanf("%d %d %d", &p1.birth.year, &p1.birth.month, &p1.birth.day);

	/* 정보를 출력함 */
	printf("\n\n<정보>\n");
	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("생년월일: %d.%d.%d\n", p1.birth.year, p1.birth.month, p1.birth.day);

	return 0;
}