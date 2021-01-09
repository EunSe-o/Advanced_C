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

	/* 정보를 입력 받음 */
	printf("이름: ");
	scanf("%s", person.name);
	printf("학번: ");
	scanf("%s", person.id);
	printf("수강 강의 수: ");
	scanf("%d", &num);

	person.attend = malloc(sizeof(student)); // 동적 메모리를 할당
	for (i = 0; i < num; i++)
	{ // 과목명과 성적을 입력 받음
		printf("강의 이름: ");
		scanf("%s", person.attend[i].name);
		printf("강의 성적: ");
		scanf("%s", person.attend[i].grade);
	}

	/* 정보 출력 */
	printf("\n\n%s의 정보\n", person.name);
	printf("이름: %s, 학번: %s\n", person.name, person.id);
	for (i = 0; i < num; i++)
		printf("과목: %s, 성적: %s\n", person.attend[i].name, person.attend[i].grade);
	printf("\n");

	free(person.attend);  // 할당 받았던 메모리 제거
	return 0;
}